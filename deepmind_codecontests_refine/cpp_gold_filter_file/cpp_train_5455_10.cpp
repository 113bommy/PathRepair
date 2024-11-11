#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, s;
  cin >> n >> m >> s;
  if (s >= n && s >= m) return cout << n * m, 0;
  long long high = (n + s - 1) / s, high1 = (m + s - 1) / s, cnt = 0, cnt1 = 0;
  for (int i = 1; i <= n; i++)
    if ((i + s - 1) / s + (n - i + s) / s - 1 == high) cnt++;
  for (int i = 1; i <= m; i++)
    if ((i + s - 1) / s + (m - i + s) / s - 1 == high1) cnt1++;
  cout << cnt * cnt1;
  return 0;
}
