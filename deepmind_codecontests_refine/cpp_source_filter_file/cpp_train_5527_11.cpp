#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, m;
int a[maxn], sum1[maxn], sum2[maxn];
int main() {
  int n, m;
  cin >> n >> m;
  a[0] = 0;
  for (int i = 1; i <= n; i++) cin >> a[i];
  a[n + 1] = m;
  sum1[1] = a[1] - a[0];
  for (int i = 2; i <= n + 1; i++) sum1[i] = sum1[i - 2] + a[i] - a[i - 1];
  sum2[n] = a[n + 1] - a[n];
  for (int i = n - 1; i >= 0; i--) sum2[i] = sum2[i + 2] + a[i] - a[i + 1];
  int ans = -1;
  if (n % 2)
    ans = sum1[n];
  else
    ans = sum1[n + 1];
  for (int i = 1; i <= n + 1; i++)
    if (a[i] - a[i - 1] != 1) {
      if (i % 2) {
        if (i == 1)
          ans = max(ans, sum2[i] + a[i] - a[i - 1] - 1);
        else
          ans = max(ans, sum1[i - 2] + sum2[i] + a[i] - a[i - 1] - 1);
      } else
        ans = max(ans, sum1[i - 1] + sum2[i + 1] + a[i] - a[i - 1] - 1);
    }
  cout << ans << endl;
}
