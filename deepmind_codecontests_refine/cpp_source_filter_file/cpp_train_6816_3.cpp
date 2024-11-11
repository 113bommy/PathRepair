#include <bits/stdc++.h>
using namespace std;
const long long int N = 100001;
bool ok;
long long int n, q;
long long int trie[6 * N][5], done[N];
long long int nxt = 1;
string s;
void insert(string s) {
  long long int node = 0;
  for (char c : s) {
    if (trie[node][c - 'a'] == 0) {
      node = trie[node][c - 'a'] = nxt++;
    } else {
      node = trie[node][c - 'a'];
    }
  }
  done[nxt - 1] = 1;
}
void dfs(long long int u, long long int idx, long long int f) {
  if (f >= 2) return;
  if (idx == s.length() - 1 && f == 1 && done[u]) {
    ok = 1;
    return;
  }
  if (idx == s.length() - 1 || done[u]) return;
  for (long long int i = 0; i < 3; i++) {
    if (trie[u][i] == 0) continue;
    if (s[idx + 1] == (char)(i + 'a'))
      dfs(trie[u][i], idx + 1, f);
    else
      dfs(trie[u][i], idx + 1, f + 1);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (long long int i = 0; i < n; i++) {
    cin >> s;
    insert(s);
  }
  for (long long int i = 0; i < q; i++) {
    cin >> s;
    ok = 0;
    dfs(0, -1, 0);
    cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}
