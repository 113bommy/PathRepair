#include <bits/stdc++.h>
using namespace std;
int n, a[1000005], L[1000005], pos[1000005];
double ans;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    L[i] = pos[a[i]];
    pos[a[i]] = i;
  }
  for (int i = 1; i <= n; i++)
    if (L[i] == i)
      ans += 2 * (n - i + 1) - 1;
    else
      ans += 2ll * (i - L[i]) * (n - i + 1) - 1;
  ans /= 1.0 * n * n;
  printf("%.10lf\n", ans);
}
