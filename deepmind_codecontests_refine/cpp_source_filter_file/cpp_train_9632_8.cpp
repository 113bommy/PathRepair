#include <bits/stdc++.h>
using namespace std;
int k, n, a[(int)(1e6 + 10)], b[(int)(1e6 + 10)], ans[(int)(1e6 + 10)], logn, l,
    r;
int mxrmq[(int)(1e6 + 10)][20], mnrmq[(int)(1e6 + 10)][20];
void init() {
  logn = log2(n);
  for (int i = 1; i <= logn; i++)
    for (int j = 1; j <= n; j++) {
      mnrmq[j][i] =
          min(mnrmq[j][i - 1], mnrmq[min(n, j + (1 << (i - 1)))][i - 1]);
      mxrmq[j][i] =
          max(mxrmq[j][i - 1], mxrmq[min(n, j + (1 << (i - 1)))][i - 1]);
    }
}
int mnq(int l, int r) {
  int logg = log2(r - l + 1);
  return min(mnrmq[l][logg], mnrmq[r - (1 << logg) + 1][logg]);
}
int mxq(int l, int r) {
  int logg = log2(r - l + 1);
  return max(mxrmq[l][logg], mxrmq[r - (1 << logg) + 1][logg]);
}
int solve(int l, int r) {
  int bas = l;
  int son = r;
  while (bas + 1 < son) {
    int ort = (bas + son) / 2;
    if (mnq(l, ort) >= mxq(l, ort))
      bas = ort;
    else
      son = ort;
  }
  if (bas == n) return min(mxq(l, bas), mnq(l, bas));
  return max(min(mxq(l, bas), mnq(l, bas)),
             min(mxq(l, bas + 1), mnq(l, bas + 1)));
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[i] *= 100;
    mxrmq[i][0] = a[i];
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    mnrmq[i][0] = b[i];
  }
  init();
  for (int i = 1; i <= n; i++) ans[i] = solve(i, n);
  sort(ans + 1, ans + n + 1);
  reverse(ans + 1, ans + n + 1);
  double x = 1.0 * k / n;
  double sum = 0;
  for (int i = n; i >= k; i--) {
    sum += ans[i] * x;
    x = x / (i - 1) / (i - k);
  }
  printf("%.12lf\n", sum);
}
