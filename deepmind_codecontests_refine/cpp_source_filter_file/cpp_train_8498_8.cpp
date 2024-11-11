#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int n, L, R, S, a[N], b[N];
int s1[N], s2[N], f[N];
int main() {
  scanf("%d%d%d", &n, &L, &R);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", &a[i]);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", &b[i]);
  for (int i = (int)(1); i <= (int)(n); i++)
    if (!b[i])
      ++s1[a[i]];
    else
      ++s2[a[i]];
  for (int i = (int)(1); i <= (int)(n); i++) S += a[i];
  swap(L, R);
  L = S - L;
  R = S - R;
  R = min(R, S);
  L = max(L, 0);
  memset(f, 233, sizeof(f));
  f[0] = 0;
  for (int i = (int)(1); i <= (int)(S); i++)
    if (s1[i]) {
      int rem = s1[i], j = i;
      for (; rem; rem -= min(rem, j), j *= 2) {
        int t = min(rem, j);
        for (int k = (int)(R); k >= (int)(i * t); k--)
          f[k] = max(f[k], f[k - i * t]);
      }
    }
  for (int i = (int)(1); i <= (int)(S); i++)
    if (s2[i]) {
      int rem = s2[i], j = i;
      for (; rem; rem -= min(rem, j), j *= 2) {
        int t = min(rem, j);
        for (int k = (int)(R); k >= (int)(i * t); k--) {
          int sum = max(0, min(k - L + 1, i * t));
          f[k] = max(f[k], f[k - i * t] + sum / i + (sum % i != 0));
        }
      }
    }
  int ans = 0;
  for (int i = (int)(L); i <= (int)(R); i++) ans = max(ans, f[i]);
  printf("%d\n", ans);
}
