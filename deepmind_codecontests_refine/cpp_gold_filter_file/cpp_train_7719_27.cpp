#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const int MX = 1e6 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  if (m == 0 or m == 1) cout << 1 << '\n', exit(0);
  if (n == m) cout << 0 << '\n', exit(0);
  int hf = n / 2;
  if (m > hf)
    cout << n - m << '\n';
  else
    cout << m << '\n';
  return 0;
}
