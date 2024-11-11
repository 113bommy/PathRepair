#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main() {
  int n, _m;
  cin >> n >> _m;
  map<string, string> m;
  for (int i = 0; i < _m; i++) {
    string a, b;
    cin >> a >> b;
    m[a] = b;
  }
  string s = "";
  for (int i = 0; i < n; i++) {
    string _;
    cin >> _;
    if (_.size() < m[_].size())
      s += _;
    else
      s += m[_];
    s += " ";
  }
  cout << s;
  return 0;
}
