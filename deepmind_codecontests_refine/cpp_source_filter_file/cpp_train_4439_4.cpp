#include <bits/stdc++.h>
using namespace std;
void solve() {}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  if (s.length() < 6) {
    cout << "NO";
  } else {
    bool ok = false;
    int z = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '1') ok = true;
      if (ok && s[i] == '0') z++;
    }
    if (z > 5 || !ok)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
