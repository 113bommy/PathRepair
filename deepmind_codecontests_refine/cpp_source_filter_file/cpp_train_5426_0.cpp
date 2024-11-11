#include <bits/stdc++.h>
#pragma GCC optimize 03
using namespace std;
const int N = 3e5 + 1;
const int LogN = 16;
int ml[LogN][4 * N], mr[LogN][4 * N], v;
int a[N];
int t[LogN];
int vl[4 * N], vr[4 * N];
void build_do(int v, int l, int r) {
  vl[v] = l;
  vr[v] = r;
  if (r - l != 1) {
    build_do(2 * v + 1, l, (l + r) / 2);
    build_do(2 * v + 2, (l + r) / 2, r);
  }
}
void alsl(int u, int i, int j) {
  i = i + v - 2;
  ml[u][i] = j;
}
int mnl, mxr;
void ans(int u, int v, int l, int r) {
  if (l <= vl[v] && vr[v] <= r) {
    if (mnl < ml[u][v]) mnl = ml[u][v];
    if (mxr > mr[u][v]) mxr = mr[u][v];
  } else if (l >= vr[v] || vl[v] >= r)
    return;
  else {
    ans(u, (v << 1) + 1, l, r);
    ans(u, (v << 1) + 2, l, r);
  }
}
void alsr(int u, int i, int j) {
  i = i + v - 2;
  mr[u][i] = j;
}
int main() {
  int i, j, k, n;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  if (n == 1) {
    cout << 0;
    return 0;
  }
  v = 1;
  while (v < 3 * n) v *= 2;
  build_do(0, 1, v + 1);
  for (i = 1; i <= n; ++i) {
    cin >> a[i];
    for (j = 0; j <= 2; ++j) {
      alsl(0, i + j * n, max(1, i + j * n - a[i]));
      alsr(0, i + j * n, min(3 * n, i + j * n + a[i]));
    }
  }
  for (j = v - 2; j >= 0; --j) {
    ml[0][j] = min(ml[0][2 * j + 1], ml[0][2 * j + 2]);
    mr[0][j] = max(mr[0][2 * j + 1], mr[0][2 * j + 2]);
  }
  for (i = 1; i < LogN; ++i) {
    for (j = 1; j <= 3 * n; ++j) {
      mnl = N;
      mxr = 0;
      ans(i - 1, 0, ml[i - 1][j + v - 2], mr[i - 1][j + v - 2] + 1);
      ml[i][j + v - 2] = mnl;
      mr[i][j + v - 2] = mxr;
    }
    for (j = v - 2; j >= 0; --j) {
      ml[i][j] = min(ml[i][2 * j + 1], ml[i][2 * j + 2]);
      mr[i][j] = max(mr[i][2 * j + 1], mr[i][2 * j + 2]);
    }
  }
  t[0] = 1;
  for (i = 1; i < LogN; ++i) t[i] = t[i - 1] * 2;
  for (i = n + 1; i <= 2 * n; ++i) {
    int l = i, r = i, as = 0;
    for (j = LogN - 1; j >= 0; --j)
      if (2 * t[j] + r - l <= n - 1) {
        mnl = N;
        mxr = 0;
        ans(j, 0, l, r + 1);
        int l1 = mnl;
        int r1 = mxr;
        if (r1 - l1 < n - 1) {
          as += t[j];
          l = l1;
          r = r1;
        }
      }
    cout << as + 1 << "\n";
  }
}
