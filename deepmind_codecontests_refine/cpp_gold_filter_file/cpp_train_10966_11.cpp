#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t, n, x, d, i, j, k;
  string s;
  cin >> n >> k;
  long long rem = k - n * 2;
  if (rem == 0)
    cout << n << '\n';
  else if (rem >= n)
    cout << 0 << '\n';
  else
    cout << n - rem << '\n';
  return 0;
}
