#include <bits/stdc++.h>
using namespace std;
const long long PR = 19260817;
vector<int> constructKMP(string pattern) {
  int n = pattern.size();
  vector<int> next(n + 1, 0);
  for (int i = 1, j = 0; i < n; i++) {
    while (j > 0 && pattern[i] != pattern[j]) j = next[j];
    if (pattern[i] == pattern[j])
      next[i] = ++j;
    else
      next[i] = j;
  }
  return next;
}
int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> v = constructKMP(s);
  for (int i = n - 1; v[i]; i = v[i]) {
    for (int j = 0; j < n - 1; j++) {
      if (v[i] == v[j]) {
        cout << s.substr(0, v[j]);
        return 0;
      }
    }
  }
  cout << "Just a legend\n";
  return 0;
}
