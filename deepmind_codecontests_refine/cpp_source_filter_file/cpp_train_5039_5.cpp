#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, sum;
int a[N];
int st[N][20];
void init() {
  for (int t = 1; t < 20; ++t) {
    for (int i = 1; i <= n; ++i) {
      if (i + (1 << t - 1) < N)
        st[i][t] = min(st[i][t - 1], st[i + (1 << t - 1)][t - 1]);
      else
        st[i][t] = st[i][t - 1];
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) scanf("%d", a + i), sum += a[i];
  for (int i = n; i; --i) {
    st[i][0] = st[i + 1][0] + a[i];
  }
  for (int i = 1; i <= n; ++i) {
    a[i] += a[i - 1];
  }
  init();
  int ans = sum;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, sum - 2 * (a[i] + st[i + 1][19]));
  }
  cout << ans << endl;
}
