#include <bits/stdc++.h>
using namespace std;
int tre[800010], lf, rt;
void updt(int x, int st, int nd) {
  if (st > rt || nd < lf) return;
  if (st == nd) {
    tre[x] = 1;
    return;
  }
  int md = (st + nd) / 2;
  updt(x * 2, st, md);
  updt(x * 2 + 1, md + 1, nd);
  tre[x] = tre[x * 2] + tre[x * 2 + 1];
}
int qry(int x, int st, int nd) {
  if (st > rt || nd < lf) return 0;
  if (st >= lf && nd <= rt) return tre[x];
  int md = (st + nd) / 2;
  return qry(x * 2, st, md) + qry(x * 2 + 1, md + 1, nd);
}
long long ans[200010];
vector<pair<long long, long long>> v[200010];
int a[200010], l2[200010], dd[200010], rr[200010], uu[200010];
map<int, map<int, int>> mp[200010];
int main() {
  int n, m, l, d, r, u;
  long long x1, x2, x3, x4, x5, x6, x7, x8, x9;
  while (cin >> n >> m) {
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
      scanf("%d%d%d%d", &l, &d, &r, &u);
      l2[i] = l;
      dd[i] = d;
      rr[i] = r;
      uu[i] = u;
      v[r + 1].push_back(make_pair(d, i));
      v[r + 1].push_back(make_pair(u + 1, i));
      v[l].push_back(make_pair(u + 1, i));
      v[l].push_back(make_pair(d, i));
      v[1].push_back(make_pair(1, i));
      v[1].push_back(make_pair(u + 1, i));
      v[1].push_back(make_pair(d, i));
      v[l].push_back(make_pair(1, i));
      v[r + 1].push_back(make_pair(1, i));
    }
    long long tmp1, tmp2, tmp;
    for (int i = n + 1; i >= 1; --i) {
      lf = rt = a[i];
      updt(1, 1, n);
      for (int j = 0; j < v[i].size(); ++j) {
        tmp1 = v[i][j].first;
        tmp2 = v[i][j].second;
        lf = tmp1;
        rt = n;
        tmp = qry(1, 1, n);
        mp[tmp2][i][tmp1] = tmp;
      }
    }
    for (int i = 0; i < m; ++i) {
      l = l2[i];
      d = dd[i];
      r = rr[i];
      u = uu[i];
      x1 = mp[i][1][u + 1] - mp[i][l][u + 1];
      x2 = mp[i][l][u + 1] - mp[i][r + 1][u + 1];
      x3 = mp[i][r + 1][u + 1];
      x4 = mp[i][1][d] - mp[i][l][d] - mp[i][1][u + 1] + mp[i][l][u + 1];
      x5 =
          mp[i][l][d] - mp[i][r + 1][d] - mp[i][l][u + 1] + mp[i][r + 1][u + 1];
      x6 = mp[i][r + 1][d] - mp[i][r + 1][u + 1];
      x7 = mp[i][1][1] + mp[i][l][d] - mp[i][l][1] - mp[i][1][d];
      x8 = mp[i][l][1] + mp[i][r + 1][d] - mp[i][l][d] - mp[i][r + 1][1];
      x9 = mp[i][r + 1][1] - mp[i][r + 1][d];
      tmp1 = x1 * (x5 + x6 + x8 + x9);
      tmp1 += x2 * (x4 + x5 + x6 + x7 + x8 + x9);
      tmp1 += x3 * (x4 + x5 + x7 + x8);
      tmp1 += x4 * (x2 + x3 + x5 + x6 + x8 + x9);
      tmp1 += x5 * (x1 + x2 + x3 + x4 + (x5 - 1) + x6 + x7 + x8 + x9);
      tmp1 += x6 * (x1 + x2 + x4 + x5 + x7 + x8);
      tmp1 += x7 * (x2 + x3 + x5 + x6);
      tmp1 += x8 * (x1 + x2 + x3 + x4 + x5 + x6);
      tmp1 += x9 * (x1 + x2 + x4 + x5);
      tmp1 /= 2;
      printf("%lld\n", tmp1);
    }
  }
  return 0;
}
