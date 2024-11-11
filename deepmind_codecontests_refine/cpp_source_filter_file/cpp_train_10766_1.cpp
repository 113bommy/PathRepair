#include <bits/stdc++.h>
using namespace std;
const int MD = 26;
const int INF = 1e9;
const int MX = 99;
int n, p1, p2, p3, d[MX][MX][MX];
char in[MD][MD];
struct el {
  int a, b, c;
  el() { a = b = c = 0; }
  el(int _a, int _b, int _c) {
    a = _a;
    b = _b;
    c = _c;
  }
  bool operator!=(el s) { return a != s.a || b != s.b || c != s.c; }
};
el p[MX][MX][MX];
void jebaj(vector<el>& Q, int a, int b, int c) {
  for (int i = 0; i < n; i++) {
    if (i != a && i != b && i != c) {
      if (in[a][i] == in[b][c] && d[i][b][c] > d[a][b][c] + 1) {
        d[i][b][c] = d[a][b][c] + 1;
        p[i][b][c] = el(a, b, c);
        Q.push_back(el(i, b, c));
      }
      if (in[b][i] == in[a][c] && d[a][i][c] > d[a][b][c] + 1) {
        d[a][i][c] = d[a][b][c] + 1;
        p[a][i][c] = el(a, b, c);
        Q.push_back(el(a, i, c));
      }
      if (in[c][i] == in[a][b] && d[a][b][i] > d[a][b][c] + 1) {
        d[a][b][i] = d[a][b][c] + 1;
        p[a][b][i] = el(a, b, c);
        Q.push_back(el(a, b, i));
      }
    }
  }
}
bool koncowy(el u) {
  return min(u.a, min(u.b, u.c)) == 0 && max(u.a, max(u.b, u.c)) == 2 &&
         u.a + u.b + u.c == 3;
}
void restore(el u) {
  vector<pair<int, int> > out;
  while (u != el(p1, p2, p3)) {
    if (u.a != p[u.a][u.b][u.c].a)
      out.push_back(make_pair(p[u.a][u.b][u.c].a, u.a));
    if (u.b != p[u.a][u.b][u.c].b)
      out.push_back(make_pair(p[u.a][u.b][u.c].b, u.b));
    if (u.c != p[u.a][u.b][u.c].c)
      out.push_back(make_pair(p[u.a][u.b][u.c].c, u.c));
    u = p[u.a][u.b][u.c];
  }
  for (int i = out.size() - 1; i >= 0; i--)
    printf("%d %d\n", out[i].first + 1, out[i].second + 1);
}
bool bfs() {
  vector<el> Q;
  for (int i = 0; i < MD; i++)
    for (int j = 0; j < MD; j++)
      for (int k = 0; k < MD; k++) d[i][j][k] = INF;
  d[p1][p2][p3] = 0;
  Q.push_back(el(p1, p2, p3));
  for (int z = 0; z < Q.size(); z++) {
    el doka = Q[z];
    el u = doka;
    jebaj(Q, u.a, u.b, u.c);
    if (koncowy(u)) {
      printf("%d\n", d[u.a][u.b][u.c]);
      restore(u);
      return true;
    }
  }
  return false;
}
int main() {
  scanf("%d", &n);
  scanf("%d%d%d", &p1, &p2, &p3);
  --p1;
  --p2;
  --p3;
  for (int i = 0; i < n; i++) {
    scanf("%s", in[i]);
  }
  if (!bfs()) printf("-1\n");
  return 0;
}
