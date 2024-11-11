#include <bits/stdc++.h>
using namespace std;
void FIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
const int mxN = 1e3 + 1;
int n, d[mxN], k;
vector<int> adj[mxN];
vector<string> a[mxN];
signed main() {
  FIO();
  cin >> n >> k;
  for (int i = 0, c; i < n; i++) {
    cin >> c;
    string s1;
    for (int j = 0; j < k; j++) {
      cin >> s1;
      a[c].push_back(s1);
    }
  }
  vector<string> s;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < k; j++) s.push_back(a[i][j]);
  n *= k;
  map<int, bool> ok;
  for (string x : s)
    for (char c : x) ok[c - 'a'] = 1;
  int al = ok.size();
  for (int i = 1; i < n; i++) {
    int n1 = s[i - 1].size(), n2 = s[i].size(), i1 = 0;
    for (; i1 < n1 || i1 < n2; i1++) {
      if (i1 >= n2 && i1 < n1) {
        cout << "IMPOSSIBLE";
        return 0;
      } else if (i1 >= n1 || i1 >= n2)
        break;
      if (s[i - 1][i1] == s[i][i1]) continue;
      adj[s[i - 1][i1] - 'a'].push_back(s[i][i1] - 'a');
      d[s[i][i1] - 'a']++;
      break;
    }
  }
  queue<int> qu;
  string ans;
  for (int i = 0; i < 26; i++)
    if (!d[i] && ok[i]) qu.push(i);
  while (qu.size()) {
    int u = qu.front();
    qu.pop();
    for (int x : adj[u]) {
      --d[x];
      if (!d[x]) qu.push(x);
    }
    ans += (char)(u + 'a');
  }
  cout << (ans.size() == al ? ans : "Impossible");
}
