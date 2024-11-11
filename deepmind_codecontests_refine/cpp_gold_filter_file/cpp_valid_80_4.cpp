#include <bits/stdc++.h>
using namespace std;
const long long int inf = 10000000000000000;
long long int mod = 1e9 + 7;
bool fun(string s) {
  for (auto x : s)
    if (x != '1') return false;
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    if (fun(s)) {
      cout << 1 << " " << n / 2 << " " << n / 2 + 1 << " " << n / 2 + n / 2
           << endl;
    } else {
      for (long long int i = 0; i < n; i++) {
        long long int ind;
        if (s[i] == '0') {
          ind = i + 1;
          if (ind <= n / 2) {
            cout << ind << " " << n << " " << ind + 1 << " " << n << endl;
            break;
          } else {
            cout << 1 << " " << ind << " " << 1 << " " << ind - 1 << endl;
            break;
          }
        }
      }
    }
  }
}
