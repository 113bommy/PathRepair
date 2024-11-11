#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
long long INFMAX = 1e16, INFMIN = -1e18;
const long long N = 2e5 + 7;
void peace(long long tc) {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long half = n / 2;
  for (long long i = 0; i < n; i++) {
    if (i + half - 1 == n - 1) {
      if (s[i - 1] == '0') {
        cout << i << " " << i + half << " " << i + 1 << " " << i + half << "\n";
        return;
      }
      break;
    }
    if (s[i + half] == '0') {
      cout << i + 1 << " " << i + half + 1 << " " << i + 1 << " " << i + half
           << "\n";
      return;
    }
    if (i != 0) {
      if (s[i - 1] == '0') {
        cout << i << " " << i + half << " " << i + 1 << " " << i + half << "\n";
        return;
      }
    }
  }
  cout << 1 << " " << half << " " << half + 1 << " " << 2 * half << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    peace(i);
  }
}
