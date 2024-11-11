#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
int a[maxn], b[maxn], d[maxn];
int n, k, A, B;
double ans = 0;
double cal() {
  double res = 0;
  for (int i = 0; i < (1 << n); i++) {
    B = 0;
    double pnow = 1;
    int num = 0;
    for (int now = 0; now < n; now++) {
      if (i & (1 << now))
        pnow = pnow * b[now + 1] / 100, num++;
      else
        pnow = pnow * (100 - b[now + 1]) / 100, B += d[now + 1];
    }
    if (num >= n / 2 + 1)
      res += pnow;
    else
      res += pnow * A / (A + B);
  }
  return res;
}
void dfs(int now, int last) {
  if (now == n + 1) {
    ans = max(ans, cal());
    return;
  }
  int en = min((100 - a[now]) / 10, last);
  for (int i = 0; i <= en; i++) {
    b[now] = a[now] + i * 10;
    dfs(now + 1, last - i);
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> k >> A;
  for (int i = 1; i <= n; i++) cin >> d[i] >> a[i];
  dfs(1, k);
  cout << fixed << setprecision(10) << ans << "\n";
}
