#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  map<string, int> m;
  for (int i = 0; i < s.size() - 1; i++) {
    m[s.substr(i, 2)]++;
  }
  int mx = 0;
  for (auto x : m) {
    mx = max(mx, x.second);
  }
  for (auto y : m) {
    if (y.second == mx) {
      cout << y.first;
      break;
    }
  }
}
