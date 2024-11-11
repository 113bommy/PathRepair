#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e9;
const int N = 2 * 1e5 + 1, MOD = 1e8;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  if (n < 3)
    cout << -1;
  else if (n % 2 != 0)
    cout << n * n / 2 << " " << (n * n + 1) / 2;
  else
    cout << n * n / 4 - 1 << " " << n * n / 4 + 1;
}
