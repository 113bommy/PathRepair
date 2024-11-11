#include <bits/stdc++.h>
using namespace std;
int p[200001][21], n, volum[500001];
int kanst(int a, int k) {
  while (k > 0) {
    int k1 = log2(k);
    a = p[a][k1];
    k -= (1 << k1);
  }
  return a;
}
int LCA(int a, int b) {
  if (a == b) return a;
  if (volum[b] > volum[a]) swap(a, b);
  if (volum[a] != volum[b]) a = kanst(a, volum[a] - volum[b]);
  if (a == b) return a;
  for (int j = 20; j >= 0; j--)
    if (p[a][j] != p[b][j]) {
      a = p[a][j];
      b = p[b][j];
    }
  return p[a][0];
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= 20; j++) p[i][j] = -1;
  int x;
  cin >> x;
  int mi = 2, mj = 1, D = 1;
  p[2][0] = 1;
  p[1][0] = -1;
  volum[1] = 0;
  volum[2] = 1;
  cout << 1 << ' ';
  for (int x, i = 3; i <= n; i++) {
    cin >> x;
    p[i][0] = x;
    volum[i] = volum[x] + 1;
    for (int j = 20; j >= 1; j--)
      if (p[i][j - 1] != -1) p[i][j] = p[p[i][j - 1]][j - 1];
    if (p[i][0] == mi) {
      mi = i;
      D++;
    } else if (p[i][0] == mj) {
      mj = i;
      D++;
    } else {
      if (volum[i] + volum[mi] - 2 * volum[LCA(i, mi)] >= D) {
        D = volum[i] + volum[mi] - 2 * volum[LCA(i, mi)];
        mj = i;
      } else if (volum[i] + volum[mj] - 2 * volum[LCA(i, mj)] >= D) {
        D = volum[i] + volum[mj] - 2 * volum[LCA(i, mj)];
        mi = i;
      }
    }
    cout << D << ' ';
  }
}
