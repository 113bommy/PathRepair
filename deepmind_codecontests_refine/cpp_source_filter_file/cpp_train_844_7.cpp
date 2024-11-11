#include <bits/stdc++.h>
using ll = long long int;
using namespace std;
bool isvalid(int n) {
  bool f = 0;
  string g = to_string(n);
  for (ll i = 0; i < g.size(); i++) {
    if (g[i] == '4' || g[i] == '7')
      continue;
    else {
      return false;
    }
  }
  return true;
}
int main() {
  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    string s = "abcd";
    string ans = "";
    for (ll i = 0; i < 3000; i++) ans += s;
    cout << ans.substr(0, n) << endl;
  }
  return 0;
}
