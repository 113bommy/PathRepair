#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int n, ans, f[N], ff[N][26];
string s;
vector<pair<int, string>> g[N];
int match(string t, int len) {
  for (int i = 0; i < t.size(); ++i) {
    len = ff[len][t[i] - 'a'];
    if (len == s.size()) ans++, len = f[len - 1];
  }
  return len;
}
void DFS(int x = 0, int len = 0) {
  for (auto u : g[x]) {
    DFS(u.first, match(u.second, len));
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    int p;
    string s;
    cin >> p >> s;
    g[p - 1].push_back({i + 1, s});
  }
  cin >> s;
  for (int i = 1, len = 0; i < s.size(); ++i) {
    while (len && s[i] != s[len]) len = f[len - 1];
    if (s[len] == s[i]) len++;
    f[i] = len;
  }
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < s.size(); ++j) {
      if (s[j] - 'a' == i)
        ff[j][i] = j + 1;
      else if (j)
        ff[j][i] = ff[f[j - 1]][i];
    }
  }
  DFS();
  cout << ans << endl;
}
