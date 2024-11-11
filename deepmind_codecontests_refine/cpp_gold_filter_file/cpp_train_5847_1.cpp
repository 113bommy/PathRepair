#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 9;
int main() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long f = 1, b = 0, r = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      if (b < r) {
        cout << 1;
        b++;
      } else {
        cout << 0;
        r++;
      }
    } else {
      if (b > r) {
        cout << 1;
        b--;
      } else {
        cout << 0;
        r--;
      }
    }
  }
}
