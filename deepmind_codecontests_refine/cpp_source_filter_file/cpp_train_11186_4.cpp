#include <bits/stdc++.h>
using namespace std;
long long x[100001][26], sze = 1;
void insert(string &s) {
  long long i = 0, v = 0;
  while (i < (long long)s.length()) {
    if (x[v][s[i] - 'a'] == -1)
      v = x[v][s[i++] - 'a'] = sze++;
    else
      v = x[v][s[i++] - 'a'];
  }
}
long long dfs(long long node) {
  for (long long i = 0; i < 26; i++) {
    long long child = x[node][i];
    if (child == -1) continue;
    long long res = dfs(child);
    if (res == 0) return 1;
  }
  return 0;
}
long long dfs2(long long node) {
  long long count = 0;
  for (long long i = 0; i < 26; i++) {
    long long child = x[node][i];
    if (child == -1) continue;
    long long res = dfs(child);
    if (res == 0) return 1;
    count++;
  }
  return count == 0;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset(x, -1, sizeof(x));
  long long n, k;
  cin >> n >> k;
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    insert(s);
  }
  long long winning = dfs(0);
  long long losing = dfs2(0);
  string winner = "First";
  if (winning == 0) {
    winner = "Second";
  } else if (losing == 0) {
    if (k % 2 == 0) winner = "Second";
  }
  cout << winner << '\n';
}
