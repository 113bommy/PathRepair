#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 9;
long long n, w, h;
struct cu {
  int no, wei;
} row[maxn], col[maxn];
bool cmp(cu a, cu b) {
  if (a.wei != b.wei) return a.wei < b.wei;
  return a.no < b.no;
}
long long res[maxn][2];
long long rowpre[maxn], rownex[maxn], colpre[maxn], colnex[maxn];
long long rowsum[maxn], colsum[maxn];
long long pos[maxn];
int main() {
  ios::sync_with_stdio(0);
  long long a, b, c, d, e, f, g;
  char tmp[2];
  long long hn = 0, wn = 0;
  while (cin >> w >> h >> n) {
    hn = wn = 0;
    for (d = 1; d <= n; d++) {
      cin >> tmp;
      cin >> e;
      if (tmp[0] == 'H') {
        row[hn].no = d;
        row[hn++].wei = e;
      } else {
        col[wn].no = d;
        col[wn++].wei = e;
      }
    }
    sort(row, row + hn, cmp);
    sort(col, col + wn, cmp);
    colsum[0] = rowsum[0] = 0;
    colsum[wn + 1] = w;
    rowsum[hn + 1] = h;
    for (d = 0; d < hn; d++) {
      pos[row[d].no] = d + 1;
      rowsum[d + 1] = row[d].wei;
      rowpre[d + 1] = rownex[d + 1] = d + 1;
    }
    rowpre[hn + 1] = rownex[hn + 1] = hn + 1;
    for (d = 0; d < wn; d++) {
      pos[col[d].no] = -d - 1;
      colsum[d + 1] = col[d].wei;
      colpre[d + 1] = colnex[d + 1] = d + 1;
    }
    colpre[wn + 1] = colnex[wn + 1] = wn + 1;
    colpre[0] = colnex[0] = rowpre[0] = rownex[0] = 0;
    res[n][0] = res[n][1] = 0;
    for (d = 0; d < hn; d++) {
      res[n][0] = max(res[n][0], rowsum[d + 1] - rowsum[d]);
    }
    for (d = 0; d < wn; d++) {
      res[n][1] = max(res[n][1], colsum[d + 1] - colsum[d]);
    }
    for (d = n; d > 1; d--) {
      if (pos[d] > 0) {
        res[d - 1][1] = res[d][1];
        e = rowpre[pos[d]];
        f = rownex[pos[d] + 1];
        res[d - 1][0] = max(res[d][0], rowsum[f] - rowsum[e - 1]);
        rownex[e] = f;
        rowpre[f] = e;
      } else {
        res[d - 1][0] = res[d][0];
        pos[d] = -pos[d];
        e = colpre[pos[d]];
        f = colnex[pos[d] + 1];
        res[d - 1][1] = max(res[d][1], colsum[f] - colsum[e - 1]);
        colnex[e] = f;
        colpre[f] = e;
      }
    }
    for (d = 1; d <= n; d++) {
      cout << res[d][0] * res[d][1] << endl;
    }
  }
  return 0;
}
