#include <bits/stdc++.h>
using namespace std;
template <class T, class T2>
inline void chkmax(T &x, const T2 &y) {
  if (x < y) x = y;
}
template <class T, class T2>
inline void chkmin(T &x, const T2 &y) {
  if (x > y) x = y;
}
const int MAXN = (1 << 20);
const int MAXC = 3017;
int n;
int add[MAXC][MAXC];
int x1[MAXN], wsdasdasd[MAXN], x2[MAXN], y2[MAXN];
bool is_upl[MAXC][MAXC];
bool is_upr[MAXC][MAXC];
bool is_downl[MAXC][MAXC];
bool is_downr[MAXC][MAXC];
int psum[4][MAXC][MAXC];
void read() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x1[i] >> wsdasdasd[i] >> x2[i] >> y2[i];
    add[x1[i]][wsdasdasd[i]]++;
    add[x1[i]][y2[i]]--;
    add[x2[i]][wsdasdasd[i]]--;
    add[x2[i]][y2[i]]++;
    is_upl[x1[i]][y2[i] - 1] = 1;
    is_upr[x2[i] - 1][y2[i] - 1] = 1;
    is_downl[x1[i]][wsdasdasd[i]] = 1;
    is_downr[x2[i] - 1][wsdasdasd[i]] = 1;
    psum[0][x1[i]][wsdasdasd[i]]++;
    psum[0][x1[i]][y2[i]]--;
    psum[1][x1[i]][wsdasdasd[i]]++;
    psum[1][x2[i]][wsdasdasd[i]]--;
    psum[2][x2[i] - 1][wsdasdasd[i]]++;
    psum[2][x2[i] - 1][y2[i]]--;
    psum[3][x1[i]][y2[i] - 1]++;
    psum[3][x2[i]][y2[i] - 1]--;
    y2[i]--;
    x2[i]--;
  }
}
int sum(int dx, int dy, int ux, int uy) {
  return add[ux][uy] - (dy > 0 ? add[ux][dy - 1] : 0) -
         (dx > 0 ? add[dx - 1][uy] : 0) +
         ((dx > 0 && dy > 0) ? add[dx - 1][dy - 1] : 0);
}
void solve() {
  for (int i = 0; i < MAXC; i++)
    for (int j = 0; j < MAXC; j++) {
      if (i > 0) add[i][j] += add[i - 1][j];
      if (j > 0) add[i][j] += add[i][j - 1];
      if (i > 0 && j > 0) add[i][j] -= add[i - 1][j - 1];
    }
  for (int i = 0; i < MAXC; i++)
    for (int j = 0; j < MAXC; j++) add[i][j] = add[i][j] > 0 ? 1 : 0;
  for (int i = 0; i < MAXC; i++)
    for (int j = 0; j < MAXC; j++) {
      if (i > 0) add[i][j] += add[i - 1][j];
      if (j > 0) add[i][j] += add[i][j - 1];
      if (i > 0 && j > 0) add[i][j] -= add[i - 1][j - 1];
    }
  for (int i = 0; i < MAXC; i++)
    for (int j = 0; j < MAXC; j++) {
      if (j > 0) psum[0][i][j] += psum[0][i][j - 1];
      if (j > 0) psum[2][i][j] += psum[2][i][j - 1];
      if (i > 0) psum[1][i][j] += psum[1][i - 1][j];
      if (i > 0) psum[3][i][j] += psum[3][i - 1][j];
    }
  for (int i = 0; i < MAXC; i++)
    for (int j = 0; j < MAXC; j++) {
      if (j > 0) psum[0][i][j] += psum[0][i][j - 1];
      if (j > 0) psum[2][i][j] += psum[2][i][j - 1];
      if (i > 0) psum[1][i][j] += psum[1][i - 1][j];
      if (i > 0) psum[3][i][j] += psum[3][i - 1][j];
    }
  for (int x = 0; x < MAXC; x++) {
    vector<int> ok;
    for (int y = 0; y < MAXC; y++) {
      if (is_downr[x][y]) ok.push_back(y);
      if (is_upr[x][y]) {
        for (auto dn : ok) {
          int l = y - dn;
          int X1 = x - l;
          if (X1 >= 0 && is_upl[X1][y] && is_downl[X1][dn] &&
              sum(X1, dn, x, y) == (l + 1) * (l + 1)) {
            if (psum[0][X1][y] - (dn > 0 ? psum[0][X1][dn - 1] : 0) != l + 1)
              continue;
            if (psum[1][x][dn] - (X1 > 0 ? psum[1][X1 - 1][dn] : 0) != l + 1)
              continue;
            if (psum[2][x][y] - (dn > 0 ? psum[2][x][dn - 1] : 0) != l + 1)
              continue;
            if (psum[3][x][y] - (X1 > 0 ? psum[3][X1 - 1][y] : 0) != l + 1)
              continue;
            cout << "YES"
                 << " ";
            vector<int> answer;
            for (int i = 0; i < n; i++)
              if (dn <= wsdasdasd[i] && wsdasdasd[i] <= y && X1 <= x1[i] &&
                  x1[i] <= x)
                answer.push_back(i + 1);
            cout << answer.size() << '\n';
            for (int p : answer) cout << p << " ";
            cout << '\n';
            return;
          }
        }
      }
    }
  }
  cout << "NO" << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  read();
  solve();
  return 0;
}
