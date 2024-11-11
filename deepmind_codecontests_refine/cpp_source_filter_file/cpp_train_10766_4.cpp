#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
struct Tri {
  int pnt[5];
};
Tri tri(int a, int b, int c) {
  int t[] = {a, b, c};
  sort(t, t + 3);
  Tri res;
  for (int i = 0; i < (3); i++) res.pnt[i] = t[i];
  return res;
}
pair<Tri, int> q[100000];
bool mark[MAXN][MAXN][MAXN];
Tri par[MAXN][MAXN][MAXN];
int dis[MAXN][MAXN][MAXN];
pair<int, int> diff[MAXN][MAXN][MAXN];
char mat[MAXN][MAXN];
int n;
void bfs(Tri s) {
  int front = 0, back = 0;
  q[0] = make_pair(s, 0);
  mark[s.pnt[0]][s.pnt[1]][s.pnt[2]] = true;
  par[s.pnt[0]][s.pnt[1]][s.pnt[2]] = s;
  while (front >= back) {
    Tri cur = q[back].first;
    int d = q[back].second + 1;
    for (int i = 0; i < (3); i++) {
      int a = cur.pnt[i], b = cur.pnt[(i + 1) % 3], c = cur.pnt[(i + 2) % 3];
      for (int j = 0; j < (n); j++)
        if (j != b && j != c && j != a && mat[a][j] == mat[b][j]) {
          Tri rem = tri(b, c, j);
          if (!mark[rem.pnt[0]][rem.pnt[1]][rem.pnt[2]]) {
            mark[rem.pnt[0]][rem.pnt[1]][rem.pnt[2]] = true;
            dis[rem.pnt[0]][rem.pnt[1]][rem.pnt[2]] = d;
            par[rem.pnt[0]][rem.pnt[1]][rem.pnt[2]] = cur;
            diff[rem.pnt[0]][rem.pnt[1]][rem.pnt[2]] = make_pair(a, j);
            front++;
            q[front] = make_pair(rem, d);
          }
        }
    }
    back++;
  }
}
bool equal(Tri a, Tri b) {
  return (a.pnt[0] == b.pnt[0] && a.pnt[1] == b.pnt[1] && a.pnt[2] == b.pnt[2]);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  int a, b, c;
  cin >> a >> b >> c;
  a--, b--, c--;
  for (int i = 0; i < (n); i++)
    for (int j = 0; j < (n); j++) cin >> mat[i][j];
  Tri s = tri(a, b, c);
  bfs(s);
  if (!mark[0][1][2]) {
    cout << -1 << endl;
    return 0;
  }
  vector<pair<int, int> > ans;
  cout << dis[0][1][2] << endl;
  Tri x = tri(0, 1, 2);
  while (!equal(x, par[x.pnt[0]][x.pnt[1]][x.pnt[2]])) {
    ans.push_back(diff[x.pnt[0]][x.pnt[1]][x.pnt[2]]);
    x = par[x.pnt[0]][x.pnt[1]][x.pnt[2]];
  }
  reverse(ans.begin(), ans.end());
  for (__typeof((ans).begin()) i = (ans).begin(); i != (ans).end(); i++)
    cout << i->first + 1 << ' ' << i->second + 1 << endl;
  {
    int _;
    cin >> _;
  }
  return 0;
}
