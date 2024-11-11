#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 100;
const int MAXM = 1e3 + 100;
const int MAXK = 1e5 + 100;
int n, m, k;
bool grid[MAXN][MAXM];
pair<int, int> stp[26 + 1];
bool havestp[26 + 1];
vector<pair<char, int> > inst;
vector<int> rowbad[MAXN];
vector<int> colbad[MAXM];
bool isValid(int r, int c) {
  if (r < 0 || c < 0 || r >= n || c >= m) return false;
  if (!grid[r][c]) return false;
  return true;
}
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};
bool move(int &r, int &c, char dir, int len) {
  int dirnum = -1;
  if (dir == 'N') dirnum = 0;
  if (dir == 'S') dirnum = 1;
  if (dir == 'E') dirnum = 2;
  if (dir == 'W') dirnum = 3;
  int nr = r + (len * dr[dirnum]);
  int nc = c + (len * dc[dirnum]);
  if (!isValid(nr, nc)) return false;
  if (dirnum == 0 || dirnum == 1) {
    if (lower_bound(colbad[c].begin(), colbad[c].end(), nr) !=
        lower_bound(colbad[c].begin(), colbad[c].end(), r))
      return false;
  } else if (dirnum == 2 || dirnum == 3) {
    if (lower_bound(rowbad[r].begin(), rowbad[r].end(), nc) !=
        lower_bound(rowbad[r].begin(), rowbad[r].end(), c))
      return false;
  }
  r = nr;
  c = nc;
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char tmp;
      cin >> tmp;
      if (tmp != '#') {
        grid[i][j] = true;
        if (tmp != '.')
          stp[tmp - 'A'] = make_pair(i, j), havestp[tmp - 'A'] = true;
      } else {
        rowbad[i].push_back(j);
        rowbad[j].push_back(i);
      }
    }
  cin >> k;
  for (int i = 0; i < k; i++) {
    char dir;
    int len;
    cin >> dir >> len;
    inst.push_back(make_pair(dir, len));
  }
  for (int i = 0; i < inst.size(); i++) {
    for (int s = 0; s < 26; s++) {
      if (!havestp[s]) continue;
      havestp[s] =
          move(stp[s].first, stp[s].second, inst[i].first, inst[i].second);
    }
  }
  bool hasstp = false;
  for (int i = 0; i < 26; i++)
    if (havestp[i]) cout << char('A' + i), hasstp = true;
  if (!hasstp) cout << "no solution";
  cout << '\n';
  return 0;
}
