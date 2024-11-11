#include <bits/stdc++.h>
using namespace std;
long long n, m;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  if (m >= n / 2)
    n = (n * (n - 1) / 2);
  else
    n = ((2 * n) - (2 * m)) - 1;
  cout << n << endl;
  cin >> n;
  return 0;
}
