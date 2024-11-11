#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  std::vector<string> v;
  for (int i = 0; i < n; i++) {
    string st;
    cin >> st;
    v.push_back(st.substr(0, 3));
    v.push_back(st.substr(5, 3));
  }
  sort(v.begin(), v.end());
  int cnt = 1, i = 0;
  while (i < v.size()) {
    if (v[i] == v[i + 1]) cnt++;
    if (v[i] != v[i + 1]) {
      if (cnt % 2 != 0 && v[i] != s) {
        cout << "contest";
        return 0;
      }
      cnt = 1;
    }
    i++;
  }
  cout << "home";
  return 0;
}
