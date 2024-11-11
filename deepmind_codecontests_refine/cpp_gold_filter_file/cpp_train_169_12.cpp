#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  string a;
  cin >> a;
  unordered_map<string, int> m;
  for (int i = 0; i < n - 1; i++) {
    string d;
    d += a[i];
    d += a[i + 1];
    if (m.find(d) == m.end())
      m[d] = 1;
    else
      m[d]++;
  }
  int ans = 0;
  string s;
  for (auto node : m) {
    if (node.second > ans) {
      ans = node.second;
      s = node.first;
    }
  }
  for (int i = 0; i < s.size(); i++) cout << s[i];
  cout << endl;
  return 0;
}
