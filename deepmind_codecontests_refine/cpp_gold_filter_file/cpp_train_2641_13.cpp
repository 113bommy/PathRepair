#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T sqr(T x) {
  return x * x;
}
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const long long LINF = INF * 1ll * INF;
const double PI = acos(-1.0);
using namespace std;
char s[500005];
int check(int mid, int cntH) {
  int tmp = mid;
  int ed = -1;
  for (int i = 0; s[i]; i++) {
    if (s[i] == 'H')
      cntH--, tmp--;
    else if (s[i] == 'S')
      tmp++;
    if (tmp >= 0 && cntH == 0) {
      ed = i;
      break;
    }
  }
  if (ed == -1) return INF;
  tmp = mid;
  int last = -1;
  int ans = INF;
  int now = 0;
  for (int i = 0; i <= ed; i++) {
    now++;
    if (s[i] == 'H') {
      tmp--;
      if (tmp == -1) last = i;
      if (~last) ans = min(ans, now + (ed - last) + (ed - i));
    } else if (s[i] == 'S') {
      tmp++;
      if (tmp == 0) {
        now += (i - last) * 2;
        last = -1;
      }
    }
  }
  return min(ans, now);
}
int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%s", s);
  int cntH = 0;
  for (int i = 0; i < n; i++) cntH += s[i] == 'H';
  int ans = -1;
  int low = 0, high = n;
  while (low <= high) {
    int mid = (low + high) >> 1;
    if (check(mid, cntH) <= m) {
      ans = mid;
      high = mid - 1;
    } else
      low = mid + 1;
  }
  printf("%d\n", ans);
}
