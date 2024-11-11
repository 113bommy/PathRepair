#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010], n, m;
int dp1[100010], dp2[100010];
void update(int &a, int b) {
  if (a < b) a = b;
}
void read() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) cin >> b[i];
  sort(a + 1, a + n + 1), sort(b + 1, b + m + 1);
}
int Dp() {
  static int head[100010];
  for (int i = 1, now = 1; i <= n; ++i) {
    head[i] = i > 1 && a[i] == a[i - 1] + 1 ? head[i - 1] : i;
    while (now <= m && b[now] <= a[i]) ++now;
    update(dp1[i], dp2[i - 1]);
    for (int j = now - 1; j >= 1 && a[i] - b[j] + 1 <= i; --j)
      update(dp1[i], dp2[head[i - (a[i] - b[j])] - 1] + now - j);
    update(dp2[i], dp1[i]), update(dp2[i], dp2[i - 1]);
    for (int j = now; j <= m && b[j] - a[i] <= n - i; ++j)
      update(dp2[i + b[j] - a[i]], dp1[i] + j - now + 1);
  }
  return dp2[n];
}
int main() {
  read();
  printf("%d\n", Dp());
  return 0;
}
