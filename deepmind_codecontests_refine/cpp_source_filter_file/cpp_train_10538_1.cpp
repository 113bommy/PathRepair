#include <bits/stdc++.h>
using namespace std;
long long const INF = 2e18 + 100;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, p, i, j;
  cin >> n >> m >> p;
  int a[n], b[m];
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) cin >> b[i];
  i = 0;
  j = 0;
  while (a[i] % p == 0) i++;
  while (b[j] % p == 0) j++;
  cout << i + j << '\n';
  return 0;
}
