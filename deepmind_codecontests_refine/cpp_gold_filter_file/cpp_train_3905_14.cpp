#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 10;
const int A = 10;
int trie[N][A], suffix[N], len[N];
int size;
void Init() {
  memset((trie), (-1), sizeof(trie));
  size = 1;
  len[0] = 0;
}
void AddString(const string &s) {
  int at = 0;
  for (char c : s) {
    int d = c - '0';
    if (trie[at][d] == -1) {
      len[size] = len[at] + 1;
      trie[at][d] = size++;
    }
    at = trie[at][d];
  }
}
void BuildAutomata() {
  int q[N];
  int h = 0, t = 0;
  for (int _n(A), d(0); d < _n; d++) {
    if (trie[0][d] != -1) {
      q[t++] = trie[0][d];
      suffix[trie[0][d]] = 0;
    } else {
      trie[0][d] = 0;
    }
  }
  suffix[0] = 0;
  while (h != t) {
    int at = q[h++];
    for (int _n(A), d(0); d < _n; d++)
      if (trie[at][d] != -1) {
        suffix[trie[at][d]] = trie[suffix[at]][d];
        q[t++] = trie[at][d];
      } else {
        trie[at][d] = trie[suffix[at]][d];
      }
  }
}
const int D = 55;
int dp[D][N][2][2][2];
const int MOD = 1e9 + 7;
void add(int &x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
int main() {
  ios_base::sync_with_stdio(false);
  string s, x, y;
  cin >> s >> x >> y;
  int d = (int)x.size();
  Init();
  for (int _n((int)s.size()), i(0); i < _n; i++) {
    string x = s.substr(i, d / 2 + 1);
    AddString(x);
  }
  BuildAutomata();
  memset((dp), (0), sizeof(dp));
  dp[0][0][0][0][0] = 1;
  for (int _n(d + 1), i(1); i < _n; i++) {
    for (int _n(size), v(0); v < _n; v++) {
      for (int _n(A), c(0); c < _n; c++) {
        for (int _n(2), k1(0); k1 < _n; k1++) {
          for (int _n(2), k2(0); k2 < _n; k2++) {
            int t1 = k1, t2 = k2;
            if (t1 == 0) {
              if (y[i - 1] - '0' < c) {
                continue;
              }
              if (y[i - 1] - '0' > c) {
                t1 = 1;
              }
            }
            if (t2 == 0) {
              if (x[i - 1] - '0' > c) {
                continue;
              }
              if (x[i - 1] - '0' < c) {
                t2 = 1;
              }
            }
            int to = trie[v][c];
            if (len[to] < d / 2) {
              add(dp[i][to][t1][t2][0], dp[i - 1][v][k1][k2][0]);
            } else {
              add(dp[i][to][t1][t2][1], dp[i - 1][v][k1][k2][0]);
            }
            add(dp[i][to][t1][t2][1], dp[i - 1][v][k1][k2][1]);
          }
        }
      }
    }
  }
  int ans = 0;
  for (int _n(size), v(0); v < _n; v++) {
    for (int _n(2), k1(0); k1 < _n; k1++) {
      for (int _n(2), k2(0); k2 < _n; k2++) {
        add(ans, dp[d][v][k1][k2][1]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
