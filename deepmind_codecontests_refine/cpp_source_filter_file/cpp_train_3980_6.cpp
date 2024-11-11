#include <bits/stdc++.h>
using namespace std;
const long long BIG = 1e8 + 5;
void solve();
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
int dt[4][2]{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int borne = 1005;
const int cm = 42;
int nbLig, nbCol, nbTyp, nbReq;
int tab[borne][borne];
vector<pair<int, int> > inc[cm];
int st[cm][borne][borne];
int mat[cm][cm];
void bfs(int typ) {
  queue<pair<int, int> > qq;
  for (auto x : inc[typ]) {
    st[typ][x.first][x.second] = 0;
    qq.push({x.first, x.second});
  }
  while (!qq.empty()) {
    int lig = qq.front().first, col = qq.front().second;
    qq.pop();
    int put = st[typ][lig][col] + 1;
    for (int iDt = (0); iDt < (4); ++iDt) {
      int nl = lig + dt[iDt][0], nc = col + dt[iDt][1];
      if (nl < 0 || nl >= nbLig || nc < 0 || nc >= nbCol) continue;
      if (st[typ][nl][nc] > put) {
        st[typ][nl][nc] = put;
        qq.push({nl, nc});
      }
    }
  }
}
void solve() {
  cin >> nbLig >> nbCol >> nbTyp;
  for (int lig = (0); lig < (nbLig); ++lig) {
    for (int col = (0); col < (nbCol); ++col) {
      int x;
      cin >> x;
      --x;
      tab[lig][col] = x;
      inc[x].push_back({lig, col});
    }
  }
  fill_n(&st[0][0][0], cm * borne * borne, BIG);
  for (int typ = (0); typ < (nbTyp); ++typ) {
    bfs(typ);
  }
  fill_n(&mat[0][0], cm * cm, BIG);
  for (int dep = (0); dep < (nbTyp); ++dep)
    for (int arr = (0); arr < (nbTyp); ++arr) {
      if (dep == arr) {
        mat[dep][arr] = 1;
        continue;
      }
      for (auto x : inc[dep]) {
        mat[dep][arr] = min(mat[dep][arr], (2 + st[arr][x.first][x.second]));
      }
      mat[arr][dep] = min(mat[arr][dep], (mat[dep][arr]));
    }
  for (int k = (0); k < (nbTyp); ++k)
    for (int i = (0); i < (nbTyp); ++i)
      for (int j = (0); j < (nbTyp); ++j) {
        mat[i][j] = min(mat[i][j], (mat[i][k] + mat[k][j]));
      }
  cin >> nbReq;
  for (int iReq = (0); iReq < (nbReq); ++iReq) {
    int l1, c1, l2, c2;
    cin >> l1 >> c1 >> l2 >> c2;
    --l1;
    --c1;
    --l2;
    --c2;
    int res = abs(l2 - l1) + abs(c2 - c1);
    for (int typ1 = (0); typ1 < (nbTyp); ++typ1)
      for (int typ2 = (0); typ2 < (nbTyp); ++typ2) {
        int sub = st[typ1][l1][c1] + mat[typ1][typ2] + st[typ2][l2][c2];
        res = min(res, (sub));
      }
    cout << res << "\n";
  }
}
