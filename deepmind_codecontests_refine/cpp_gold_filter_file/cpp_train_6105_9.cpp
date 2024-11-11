#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return ((a * b) / gcd(a, b)); }
long long dp[200][200][100];
long long n, m;
vector<pair<long long, long long> > *adj =
    new vector<pair<long long, long long> >[100000];
bool solve(long long u, long long v, long long cost) {
  if (dp[u][v][cost] != -1) {
    return dp[u][v][cost] == 0;
  }
  bool win = false;
  for (long long i = 0; i < adj[u].size(); i++) {
    long long nextNode = adj[u][i].first;
    long long nextChar = adj[u][i].second;
    if (nextChar >= cost && solve(v, nextNode, nextChar) == false) {
      win = true;
    }
  }
  if (win == true) {
    dp[u][v][cost] = 0;
  } else {
    dp[u][v][cost] = 1;
  }
  return dp[u][v][cost] == 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  memset(dp, -1, sizeof(dp));
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long long u, v;
    char ch;
    cin >> u >> v >> ch;
    adj[u].push_back(make_pair(v, ch - 'a'));
  }
  for (long long i = 1; i < n + 1; i++) {
    for (long long j = 1; j < n + 1; j++) {
      if (solve(i, j, 0)) {
        cout << 'A';
      } else {
        cout << 'B';
      }
    }
    cout << '\n';
  }
  return 0;
}
