#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
int a[maxn], p[maxn], c[maxn];
int d1[maxn][19], log_2[maxn];
int n, d;
void RMQ_init() {
  log_2[1] = 0;
  for (int i = 2; i <= n; i++) {
    log_2[i] = log_2[i - 1];
    if ((1 << log_2[i] + 1) == i) ++log_2[i];
  }
  for (int i = 0; i < n; i++) d1[i][0] = p[i];
  for (int j = 1; (1 << j) <= n; j++)
    for (int i = 0; i + (1 << j) - 1 < n; i++) {
      d1[i][j] = max(d1[i][j - 1], d1[i + (1 << (j - 1))][j - 1]);
    }
}
int MAX(int l, int r) {
  int k = log_2[r - l + 1];
  return max(d1[l][k], d1[r - (1 << k) + 1][k]);
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> d;
  bool ok = 1, noans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    p[i] = a[i];
    if (i) p[i] += p[i - 1];
    if (a[i] == 0 && p[i] < 0) ok = 0;
    if (p[i] > d) noans = 1;
  }
  if (noans) {
    cout << -1 << endl;
    return 0;
  }
  RMQ_init();
  for (int i = 0; i < n; i++) {
    c[i] = d - MAX(i + 1, n - 1);
  }
  ok = 1;
  int pls = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0 && p[i] + pls < 0) {
      if (c[i] > pls) {
        pls += c[i] - pls;
        cnt++;
      }
      if (p[i] + pls < 0) {
        ok = 0;
        break;
      }
    }
  }
  if (ok) {
    cout << cnt << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
