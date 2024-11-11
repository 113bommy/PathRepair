#include <bits/stdc++.h>
using namespace std;
const int MX = 1 << 22;
const int MOD = 1000000007;
const int64_t mod2 = 1000000007 * 1LL * 1000000007;
const double PI =
    3.141592653589793238462643383279502884197169399375105820974944;
int64_t strtoll(string second) {
  stringstream str(second);
  int64_t number = 0;
  str >> number;
  return number;
}
int64_t r() { return (rand() * 32000LL + rand()) % 1000003; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  for (int tt = 1; tt <= t; tt++) {
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];
    int exp = 0;
    for (int i = 0; i < n; i++) {
      if (ar[i] > exp) return cout << exp + 1, 0;
      if (ar[i] == exp) exp++;
    }
    cout << "-1\n";
  }
  return 0;
}
