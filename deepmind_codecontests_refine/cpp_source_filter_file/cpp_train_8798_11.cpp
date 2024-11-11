#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<string> v;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    v.push_back(s);
  }
  set<string> s;
  for (int i = n - 1; i >= 0; i--) {
    if (s.find(v[i]) != s.end()) {
      cout << v[i] << "\n";
      s.insert(v[i]);
    }
  }
  return 0;
}
