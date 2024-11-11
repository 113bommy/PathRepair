#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
const int M = 260;
const long long mod = 1e9 + 7;
const long long MOD = 998244353;
const long double eps = 0.000000001;
const int P = 1336;
const int inf = 100;
mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
vector<int> a, b, c;
int dp[M][M][M];
int p[N][26];
void rec(int i, int j, int z) {
  if (dp[i][j][z] == inf) return;
  if (i + 1 < a.size())
    dp[i + 1][j][z] = min(dp[i + 1][j][z], p[dp[i][j][z]][a[i + 1]]);
  if (j + 1 < b.size())
    dp[i][j + 1][z] = min(dp[i][j + 1][z], p[dp[i][j][z]][b[j + 1]]);
  if (z + 1 < c.size())
    dp[i][j][z + 1] = min(dp[i][j][z + 1], p[dp[i][j][z]][c[z + 1]]);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));
  a.push_back(0);
  b.push_back(0);
  c.push_back(0);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  s = " " + s;
  n++;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      for (int z = 0; z < M; z++) {
        dp[i][j][z] = inf;
      }
    }
  }
  dp[0][0][0] = 0;
  for (int j = 0; j < 26; j++) {
    p[n - 1][j] = inf;
  }
  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j < 26; j++) {
      p[i][j] = p[i + 1][j];
    }
    int cc = int(s[i + 1] - 'a');
    p[i][cc] = i + 1;
  }
  while (q--) {
    char cc;
    cin >> cc;
    if (cc == '+') {
      int nom;
      cin >> nom;
      char x1;
      cin >> x1;
      int x = int(x1 - 'a');
      if (nom == 1) a.push_back(x);
      if (nom == 2) b.push_back(x);
      if (nom == 3) c.push_back(x);
      for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
          if (nom == 1) rec(int32_t(a.size()) - 2, i, j);
          if (nom == 2) rec(i, int32_t(b.size()) - 2, j);
          if (nom == 3) rec(i, j, int32_t(c.size()) - 2);
        }
      }
      for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
          if (nom == 1) rec(int32_t(a.size()) - 1, i, j);
          if (nom == 2) rec(i, int32_t(b.size()) - 1, j);
          if (nom == 3) rec(i, j, int32_t(c.size()) - 1);
        }
      }
    } else {
      int nom;
      cin >> nom;
      for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
          if (nom == 1) dp[a.size() - 1][i][j] = inf;
          if (nom == 2) dp[i][b.size() - 1][j] = inf;
          if (nom == 3) dp[i][j][c.size() - 1] = inf;
        }
      }
      if (nom == 1) a.pop_back();
      if (nom == 2) b.pop_back();
      if (nom == 3) c.pop_back();
    }
    if (dp[a.size() - 1][b.size() - 1][c.size() - 1] != inf)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
