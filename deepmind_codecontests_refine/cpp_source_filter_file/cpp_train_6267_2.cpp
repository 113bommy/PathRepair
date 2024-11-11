#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const double Pi = 3.1415926535897932;
const int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
const int maxn = 1e5 + 5;
int n;
int pos[maxn];
int pn;
long long s[maxn];
long long solve(int len) {
  if (len <= 1) return 1e18;
  long long ans = 0;
  int en;
  for (int i = 1; i <= pn; i = en + 1) {
    en = i + len - 1;
    int mid = i + (len - i) / 2;
    ans += (mid - i + 1) * s[mid] - (s[mid] - s[i - 1]);
    ans += (s[en] - s[mid]) - (en - mid) * s[mid];
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    if (a) pos[++pn] = i;
  }
  if (pn == 1) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i <= pn; i++) s[i] = s[i - 1] + pos[i];
  int t = sqrt(pn);
  if ((t + 1) * (t + 1) == pn) t++;
  long long ans = 1e18;
  for (int i = 1; i <= t; i++)
    if (pn % i == 0) {
      ans = min(ans, solve(i));
      ans = min(ans, solve(pn / i));
    }
  printf("%lld\n", ans);
  return 0;
}
