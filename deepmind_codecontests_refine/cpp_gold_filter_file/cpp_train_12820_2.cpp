#include <bits/stdc++.h>
using namespace std;
const long long MAX = 256;
int d[MAX][MAX][MAX];
int INF = 1000000;
string w;
int nxt[128000][32];
int next(char c, int off) {
  off++;
  if (off >= w.size()) return off;
  return nxt[off][c - 'a'];
}
int main() {
  long long n, q;
  cin >> n >> q;
  cin >> w;
  int pos[32];
  for (int i = 0; i < 32; i++) pos[i] = w.size() * 3 + 100;
  for (int i = w.size() - 1; i >= 0; i--) {
    pos[w[i] - 'a'] = i;
    for (int j = 0; j < 32; j++) nxt[i][j] = pos[j];
  }
  vector<string> r(3);
  memset(d, 100, sizeof(d));
  d[0][0][0] = -1;
  for (int ii = 0; ii < q; ii++) {
    char act = '?', c = '?';
    int rn = -1;
    cin >> act >> rn;
    rn--;
    if (act == '+') {
      cin >> c;
      r[rn].push_back(c);
      int i = r[0].size(), j = r[1].size(), k = r[2].size();
      switch (rn) {
        case 0:
          for (j = 0; j <= r[1].size(); j++)
            for (k = 0; k <= r[2].size(); k++) {
              int rr = INF;
              if (i > 0 && d[i - 1][j][k] < (int)w.size())
                rr = min(next(r[0][i - 1], d[i - 1][j][k]), rr);
              if (j > 0 && d[i][j - 1][k] < (int)w.size())
                rr = min(next(r[1][j - 1], d[i][j - 1][k]), rr);
              if (k > 0 && d[i][j][k - 1] < (int)w.size())
                rr = min(next(r[2][k - 1], d[i][j][k - 1]), rr);
              d[i][j][k] = rr;
            }
          break;
        case 1:
          for (i = 0; i <= r[0].size(); i++)
            for (k = 0; k <= r[2].size(); k++) {
              int rr = INF;
              if (i > 0 && d[i - 1][j][k] < (int)w.size())
                rr = min(next(r[0][i - 1], d[i - 1][j][k]), rr);
              if (j > 0 && d[i][j - 1][k] < (int)w.size())
                rr = min(next(r[1][j - 1], d[i][j - 1][k]), rr);
              if (k > 0 && d[i][j][k - 1] < (int)w.size())
                rr = min(next(r[2][k - 1], d[i][j][k - 1]), rr);
              d[i][j][k] = rr;
            }
          break;
        case 2:
          for (i = 0; i <= r[0].size(); i++)
            for (j = 0; j <= r[1].size(); j++) {
              int rr = INF;
              if (i > 0 && d[i - 1][j][k] < (int)w.size())
                rr = min(next(r[0][i - 1], d[i - 1][j][k]), rr);
              if (j > 0 && d[i][j - 1][k] < (int)w.size())
                rr = min(next(r[1][j - 1], d[i][j - 1][k]), rr);
              if (k > 0 && d[i][j][k - 1] < (int)w.size())
                rr = min(next(r[2][k - 1], d[i][j][k - 1]), rr);
              d[i][j][k] = rr;
            }
          break;
      }
    } else {
      r[rn].pop_back();
    }
    if (d[r[0].size()][r[1].size()][r[2].size()] < (int)w.size()) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
