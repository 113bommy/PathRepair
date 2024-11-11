#include <bits/stdc++.h>
using namespace std;
int trie[2000005][26];
int cntWord[2000005];
int win[2000005];
int lose[2000005];
long long maxx = 0;
int cnt = 0;
void add(string s) {
  int len = s.length();
  int node = 0;
  for (int i = 0; i < len; i++) {
    if (trie[node][s[i] - 'a'] == 0) trie[node][s[i] - 'a'] = ++cnt;
    node = trie[node][s[i] - 'a'];
  }
  cntWord[node]++;
}
void prep() {
  for (int i = cnt; i >= 0; i--) {
    bool flag = false;
    for (int j = 0; j <= 25; j++)
      if (trie[i][j]) {
        win[i] |= !win[trie[i][j]];
        lose[i] |= !lose[trie[i][j]];
        flag = true;
      }
    if (!flag) lose[i] = true;
  }
}
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    string x;
    cin >> x;
    add(x);
  }
  prep();
  if (!win[0])
    cout << "Second";
  else if (win[0] && lose[0])
    cout << "First";
  else if (win[0] && !lose[0] && k % 2)
    cout << "First";
  else
    cout << "Second";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
