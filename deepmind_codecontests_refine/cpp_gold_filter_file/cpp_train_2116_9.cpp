#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string s;
  set<char> se[101];
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) se[j].insert(s[j]);
  }
  long long ans = 1;
  for (int i = 0; i < m; i++) ans = (ans * se[i].size()) % 1000000007;
  cout << ans << endl;
  return 0;
}
