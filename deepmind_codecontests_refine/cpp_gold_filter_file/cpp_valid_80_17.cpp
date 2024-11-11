#include <bits/stdc++.h>
using namespace std;
const int inf = 1e6 + 6;
map<long long, bool> mp;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool flag = 0;
    for (int i = 0; i < n / 2; i++) {
      if (s[i] == '0') {
        flag = 1;
        cout << i + 1 << ' ' << n << ' ' << i + 2 << ' ' << n << '\n';
        break;
      }
    }
    if (flag) continue;
    for (int i = n / 2; i < n; i++) {
      if (s[i] == '0') {
        flag = 1;
        cout << 1 << ' ' << i + 1 << ' ' << 1 << ' ' << i << '\n';
        break;
      }
    }
    if (flag) continue;
    cout << 1 << ' ' << n / 2 << ' ' << 2 << ' ' << n / 2 + 1 << '\n';
  }
  return 0;
}
