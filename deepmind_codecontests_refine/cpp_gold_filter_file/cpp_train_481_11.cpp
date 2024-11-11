#include <bits/stdc++.h>
using namespace std;
long long mat[8][64][3][3];
long long ans[3], sv[3];
int cnt[3];
vector<pair<long long, int> > qr;
void gop(long long y, int x) {
  int idx = 0;
  while (y) {
    if (y % 2 == 1) {
      for (int i = 0; i < 3; i++) {
        sv[i] = ans[i];
        ans[i] = 0;
      }
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          ans[i] += (mat[x][idx][i][j] * sv[j]);
          ans[i] %= 1000000007;
        }
      }
    }
    y /= 2;
    idx++;
  }
}
int main() {
  int n;
  long long m;
  scanf("%d", &n);
  scanf("%lld", &m);
  for (int t = 0; t < 8; t++) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if ((t & (1 << i)) == 0) mat[t][0][i][j] = 1;
      }
    }
    mat[t][0][0][2] = mat[t][0][2][0] = 0;
    for (int i = 1; i <= 63; i++) {
      for (int ii = 0; ii < 3; ii++) {
        for (int kk = 0; kk < 3; kk++) {
          for (int jj = 0; jj < 3; jj++) {
            mat[t][i][ii][jj] += mat[t][i - 1][ii][kk] * mat[t][i - 1][kk][jj];
            mat[t][i][ii][jj] %= 1000000007;
          }
        }
      }
    }
  }
  ans[1] = 1;
  for (int i = 0; i < n; i++) {
    int aa;
    long long bb, cc;
    scanf("%d%lld%lld", &aa, &bb, &cc);
    qr.push_back({bb - 1, aa});
    qr.push_back({cc, -aa});
  }
  qr.push_back({m, 0});
  sort(qr.begin(), qr.end());
  long long until = 1;
  int status = 0;
  for (auto &q : qr) {
    gop(q.first - until, status);
    if (q.second > 0) {
      cnt[q.second - 1]++;
    }
    if (q.second < 0) {
      cnt[-q.second - 1]--;
    }
    status = 0;
    for (int i = 0; i < 3; i++) {
      if (cnt[i] > 0) status += (1 << i);
    }
    until = q.first;
  }
  printf("%lld\n", ans[1]);
}
