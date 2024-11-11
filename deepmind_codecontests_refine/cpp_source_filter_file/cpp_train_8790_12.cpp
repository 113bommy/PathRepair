#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (n > m) swap(n, m);
  if (k < n)
    cout << max((int)(n / (k + 1)) * m, (int)(m / (k + 1)) * n);
  else if (k >= n && k < m)
    cout << int(m / (k + 1)) * n;
  else if (k >= m && k <= (n + m - 2))
    cout << int(n / (k - m + 2));
  else
    cout << -1;
  return 0;
}
