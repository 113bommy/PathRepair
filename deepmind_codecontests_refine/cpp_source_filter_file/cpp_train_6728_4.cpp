#include <bits/stdc++.h>
using namespace std;
const int N = 1050;
const double eps = 1e-4;
void read(int &x) {
  char c = getchar();
  x = 0;
  bool f = 0;
  while (!isdigit(c)) f |= (c == '-'), c = getchar();
  while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
  if (f) x = -x;
}
int dcmp(double x) { return x < -eps ? -1 : x > eps; }
int n, tt = 0, x[N], y[N], sumx = 0, sumy = 0, ans = 0;
double may[N * N], sx, sy, tax[N];
bool del[N];
map<pair<int, int>, bool> vis;
void check(double k) {
  int tnum = 0;
  double mid;
  for (int i = 1; i <= n; i++) tax[++tnum] = (k * y[i] + x[i]) / (k * k + 1);
  sort(tax + 1, tax + tnum + 1);
  mid = (tax[1] + tax[tnum]) / 2;
  for (int i = 2; i <= (tnum + 1) / 2; i++)
    if (dcmp(mid + mid - tax[i] - tax[tnum - i + 1]) != 0) return;
  ++ans;
  return;
}
int main() {
  int T, X, Y, tp = 0;
  read(n);
  for (int i = 1; i <= n; i++) {
    read(X), read(Y);
    if (!vis[pair<int, int>(X, Y)]) {
      x[++tp] = X, y[tp] = Y;
      vis[pair<int, int>(X, Y)] = 1;
      sumx += X, sumy += Y;
    }
  }
  n = tp, sx = 1.0 * sumx / n, sy = 1.0 * sumy / n;
  double XX, YY;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (del[j]) continue;
      YY = 1.0 * (y[i] + y[j]) / 2, XX = 1.0 * (x[i] + x[j]) / 2;
      if (dcmp(YY - sy) == 0 && dcmp(XX - sx) == 0) {
        del[i] = del[j] = 1;
        break;
      }
    }
  }
  tp = 0;
  for (int i = 1; i <= n; i++) {
    if (!del[i]) ++tp, x[tp] = x[i], y[tp] = y[i];
  }
  n = tp;
  if (n <= 1) return puts("-1"), 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      YY = (y[i] + y[j]) / 2.0, XX = (x[i] + x[j]) / 2.0;
      if (dcmp(YY - sy) == 0) continue;
      may[++tt] = 1.0 * (XX - sx) / (sy - YY);
    }
  }
  sort(may + 1, may + tt + 1);
  for (int i = 1, j; i <= tt;) {
    j = i;
    while (j + 1 <= tt && dcmp(may[j + 1] - may[i]) == 0) ++j;
    if ((j - i + 1) >= n / 2) check(may[i]);
    i = j + 1;
  }
  bool flag = 1;
  double mid;
  sort(y + 1, y + n + 1), mid = (y[1] + y[n]) / 2.0;
  for (int i = 2; i <= (n + 1) / 2; i++)
    if (dcmp(mid + mid - y[i] - y[n - i + 1]) != 0) {
      flag = 0;
      break;
    }
  ans += flag;
  printf("%d\n", ans);
}
