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
char s[100005];
int cnt[100005][3];
int mp[128];
int main(void) {
  mp['z'] = 2;
  mp['y'] = 0;
  mp['x'] = 1;
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) cnt[i][j] = cnt[i - 1][j];
    cnt[i][mp[s[i - 1]]]++;
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    if (r - l + 1 < 3)
      puts("YES");
    else {
      int a[3];
      for (int i = 0; i < 3; i++) a[i] = cnt[r][i] - cnt[l - 1][i];
      sort(a, a + 3);
      a[2] -= a[0];
      if (a[2] <= 1 && a[0])
        puts("YES");
      else
        puts("NO");
    }
  }
}
