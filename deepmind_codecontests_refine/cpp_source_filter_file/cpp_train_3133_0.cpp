#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string s, t;
  cin >> s >> t;
  vector<char> v1, v2;
  int n1 = s.size(), n2 = t.size();
  for (int i = 0; i < n1; i++) {
    v1.push_back(s[i]);
  }
  for (int i = 0; i < n2; i++) {
    v2.push_back(t[i]);
  }
  int br = 0;
  while (1) {
    if (v1.back() == v2.back()) {
      br++;
      v1.pop_back();
      v2.pop_back();
    } else
      break;
  }
  cout << (n1 - br) + (n2 - br);
  return 0;
}
