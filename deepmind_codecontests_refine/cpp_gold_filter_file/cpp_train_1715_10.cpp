#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10, MAXLG = 20, INF = 2e9 + 10;
int p[MAXN], l[MAXN], lg[MAXN];
int rmq[MAXN][MAXLG], len[MAXLG][MAXN], nxt[MAXLG][MAXN];
int askrmq(int s, int e) {
  int lenq = e - s;
  if (lenq < 1) return -1;
  return max(rmq[s][lg[lenq]], rmq[e - (1 << lg[lenq])][lg[lenq]]);
}
int main() {
  for (int i = 2; i < MAXN; i++) lg[i] = lg[i / 2] + 1;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> p[i] >> l[i];
  p[n] = INF;
  for (int i = n - 1; i >= 0; i--) {
    int lastP = p[i] + l[i];
    int hi = upper_bound(p, p + n, lastP) - p;
    if (hi > i + 1) lastP = max(lastP, askrmq(i + 1, hi));
    rmq[i][0] = lastP;
    for (int j = 1; j < MAXLG; j++) {
      if (i + (1 << j) >= n)
        rmq[i][j] = rmq[i][j - 1];
      else
        rmq[i][j] = max(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
    }
    hi = upper_bound(p, p + n, lastP) - p;
    len[0][i] = p[hi] - lastP;
    nxt[0][i] = hi;
    for (int j = 1; j < MAXLG; j++) {
      nxt[j][i] = nxt[j - 1][i] == n ? n : nxt[j - 1][nxt[j - 1][i]];
      len[j][i] = nxt[j - 1][i] == n
                      ? len[j - 1][i]
                      : len[j - 1][i] + len[j - 1][nxt[j - 1][i]];
    }
  }
  int qs;
  cin >> qs;
  for (int i = 0; i < qs; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    int ansQ = 0;
    for (int j = MAXLG - 1; j >= 0; j--)
      if (nxt[j][x] <= y) {
        ansQ += len[j][x];
        x = nxt[j][x];
      }
    cout << ansQ << "\n";
  }
  return 0;
}
