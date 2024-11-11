#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
long long solve(long long n) {
  if (n == 1 || n == 0) {
    return 1;
  } else {
    return (((solve(n - 1) % mod) * (solve(n - 1) % mod)) +
            ((2 * (solve(n - 1) % mod) * (solve(n - 2) % mod)) % mod));
  }
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string str;
  cin >> str;
  sort(str.begin(), str.end());
  for (int i = str.size() - 1; i >= 0; i--) {
    if (str[i] != str[str.size() - 1]) {
      break;
    }
    cout << str[i];
  }
  return 0;
}
