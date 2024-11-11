#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-8;
int n;
int l[6][6];
int h[6][6];
int a[6][6];
int memo[7][6][11][16][21];
const int INF = 1000000000;
void perm(int org, int d, int amo, vector<int> &p, vector<vector<int> > &dist) {
  if (d == n) {
    if (amo == 0) dist.push_back(p);
    return;
  }
  for (int i = l[org][d]; i <= min(amo, h[org][d]); i++) {
    p[d - 1 - org] = i;
    perm(org, d + 1, amo - i, p, dist);
  }
}
int rec(int d, vector<int> &flow) {
  int res = -INF;
  if (d == n - 1) return 0;
  if (d > 0 && memo[d][flow[1]][flow[2]][flow[3]][flow[4]] >= -INF)
    return memo[d][flow[1]][flow[2]][flow[3]][flow[4]];
  vector<vector<int> > dist;
  vector<int> p(n - 1 - d);
  perm(d, d + 1, flow[d], p, dist);
  for (int i = 0; i < (int)dist.size(); i++) {
    vector<int> nflow(6, 0);
    int cost = 0;
    for (int j = d + 1; j < n; j++) {
      nflow[j] = flow[j] + dist[i][j - 1 - d];
      if (dist[i][j - 1 - d] > 0) cost += a[d][j];
      cost += dist[i][j - 1 - d] * dist[i][j - 1 - d];
    }
    res = max(res, cost + rec(d + 1, nflow));
  }
  memo[d][flow[1]][flow[2]][flow[3]][flow[4]] = res;
  return res;
}
int main() {
  istream &fin = cin;
  ostream &fout = cout;
  FILE *fpin = stdin;
  FILE *fpout = stdout;
  fin >> n;
  int e = n * (n - 1) / 2;
  for (int i = 0; i < e; i++) {
    int s, f;
    fin >> s >> f;
    s--;
    f--;
    fin >> l[s][f] >> h[s][f] >> a[s][f];
  }
  memset(memo, -127, sizeof(memo));
  vector<int> flow(6, 0);
  for (int i = 0; i < n; i++) flow[i] = 0;
  for (int i = 0; i <= 25; i++) {
    flow[0] = i;
    int res = rec(0, flow);
    if (res >= 0) {
      fout << i << " " << res << endl;
      return 0;
    }
  }
  fout << -1 << " " << -1 << endl;
}
