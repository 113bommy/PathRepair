#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, m;
int clauses[123123][2];
vector<int> uses[123123];
bool vis[123123];
vector<int> chain[123123];
int counter;
vector<pair<long long, long long>> dips;
long long ans;
int rightc(int cnr) {
  int xnr = abs(clauses[cnr][1]);
  if (uses[xnr].size() == 2) {
    return uses[xnr][0] == cnr ? uses[xnr][1] : uses[xnr][0];
  } else {
    return 0;
  }
}
void load() {
  cin >> n >> m;
  int k;
  for (int i = 1; i <= n; ++i) {
    cin >> k;
    for (int j = 0; j < k; ++j) {
      cin >> clauses[i][j];
      uses[abs(clauses[i][j])].push_back(i);
    }
  }
}
void dfs(int cnr, int from) {
  if (vis[cnr]) {
    return;
  }
  vis[cnr] = 1;
  if (abs(clauses[cnr][1]) == from) {
    swap(clauses[cnr][0], clauses[cnr][1]);
  }
  chain[counter].push_back(cnr);
  dfs(rightc(cnr), abs(clauses[cnr][1]));
}
void dfs2(int cnr, int from, int f) {
  if (vis[cnr]) {
    return;
  }
  vis[cnr] = 1;
  if (!clauses[cnr][1]) {
    if (!f) {
      swap(clauses[cnr][0], clauses[cnr][1]);
    }
  } else {
    if (abs(clauses[cnr][1]) == from) {
      swap(clauses[cnr][0], clauses[cnr][1]);
    }
  }
  chain[counter].push_back(cnr);
  dfs2(rightc(cnr), abs(clauses[cnr][1]), 1);
}
void buildChains() {
  vis[0] = 1;
  for (int i = 1; i <= m; ++i)
    if (uses[i].size() == 1 && !vis[uses[i][0]]) {
      dfs(uses[i][0], i);
      ++counter;
    }
  for (int i = 1; i <= m; ++i)
    if (uses[i].size() == 2) {
      if (!vis[uses[i][0]] && !clauses[uses[i][0]][1]) {
        dfs2(uses[i][0], i, 0);
        ++counter;
      }
      if (!vis[uses[i][1]] && !clauses[uses[i][1]][1]) {
        dfs2(uses[i][1], i, 0);
        ++counter;
      }
    }
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) {
      dfs(i, abs(clauses[i][0]));
      ++counter;
    }
}
long long dp[123123][2][2][2];
int val(int i, int j, int nr) {
  int v1 = i;
  if (clauses[nr][0] < 0) {
    v1 = 1 - v1;
  }
  if (clauses[nr][0] == 0) {
    v1 = 0;
  }
  int v2 = j;
  if (clauses[nr][1] < 0) {
    v2 = 1 - v2;
  }
  if (clauses[nr][1] == 0) {
    v2 = 0;
  }
  return (v1 | v2);
}
void cleaar(int si) {
  for (int i = 0; i < si; ++i)
    for (int j = 0; j < 2; ++j)
      for (int l = 0; l < 2; ++l)
        for (int k = 0; k < 2; ++k) dp[i][j][l][k] = 0;
}
void consider(int nr) {
  if (chain[nr].size() == 1 &&
      abs(clauses[chain[nr][0]][0]) == abs(clauses[chain[nr][0]][1])) {
    if (clauses[chain[nr][0]][0] == clauses[chain[nr][0]][1]) {
      dips.push_back(make_pair(1, 1));
    } else {
      dips.push_back(make_pair(2, 0));
    }
    return;
  }
  cleaar(chain[nr].size());
  int fi = chain[nr][0];
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) dp[0][i][j][val(i, j, fi)] = 1;
  for (int i = 0; i < chain[nr].size() - 1; ++i)
    for (int j = 0; j < 2; ++j)
      for (int l = 0; l < 2; ++l)
        for (int k = 0; k < 2; ++k) {
          dp[i + 1][j][0][val(l, 0, chain[nr][i + 1]) ^ k] += dp[i][j][l][k];
          dp[i + 1][j][0][val(l, 0, chain[nr][i + 1]) ^ k] %= mod;
          dp[i + 1][j][1][val(l, 1, chain[nr][i + 1]) ^ k] += dp[i][j][l][k];
          dp[i + 1][j][1][val(l, 1, chain[nr][i + 1]) ^ k] %= mod;
        }
  int si = chain[nr].size();
  if (!clauses[chain[nr][0]][0] && !clauses[chain[nr][si - 1]][1]) {
    dips.push_back(make_pair(dp[si - 1][0][0][0], dp[si - 1][0][0][1]));
    return;
  }
  if (!clauses[chain[nr][si - 1]][1]) {
    long long r0 = (dp[si - 1][0][0][0] + dp[si - 1][1][0][0]) % mod;
    long long r1 = (dp[si - 1][0][0][1] + dp[si - 1][1][0][1]) % mod;
    dips.push_back(make_pair(r0, r1));
    return;
  }
  if (abs(clauses[chain[nr][0]][0]) != abs(clauses[chain[nr][si - 1]][1])) {
    long long r0 = (dp[si - 1][0][0][0] + dp[si - 1][1][1][0] +
                    dp[si - 1][0][1][0] + dp[si - 1][1][0][0]) %
                   mod;
    long long r1 = (dp[si - 1][0][0][1] + dp[si - 1][1][1][1] +
                    dp[si - 1][0][1][1] + dp[si - 1][1][0][1]) %
                   mod;
    dips.push_back(make_pair(r0, r1));
    return;
  }
  long long r0 = (dp[si - 1][0][0][0] + dp[si - 1][1][1][0]) % mod;
  long long r1 = (dp[si - 1][0][0][1] + dp[si - 1][1][1][1]) % mod;
  dips.push_back(make_pair(r0, r1));
}
void makeAns() {
  long long a = dips[0].first;
  long long b = dips[0].second;
  for (int i = 1; i < counter; ++i) {
    long long c = (a * dips[i].first + b * dips[i].second) % mod;
    long long d = (a * dips[i].second + b * dips[i].first) % mod;
    a = c;
    b = d;
  }
  ans = b;
  for (int i = 1; i <= m; ++i)
    if (uses[i].empty()) {
      ans *= 2;
      ans %= mod;
    }
}
void debug() {
  return;
  for (int i = 0; i < counter; ++i) {
    cerr << i << " : ";
    for (int ind : chain[i]) {
      cerr << "(" << clauses[ind][0] << ", " << clauses[ind][1] << ") ";
    }
    cerr << endl;
  }
  for (auto tmp : dips) {
    cerr << tmp.first << " " << tmp.second << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  load();
  buildChains();
  for (int i = 0; i < counter; ++i) {
    consider(i);
  }
  debug();
  makeAns();
  cout << ans << endl;
}
