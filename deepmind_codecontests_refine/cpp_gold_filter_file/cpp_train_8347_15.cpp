#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int n;
int pre[N], nxt[N], s[N];
int sum(int i, int j) { return s[j] - s[i - 1]; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  memset(pre, -1, sizeof(pre));
  memset(s, 0, sizeof(s));
  memset(nxt, -1, sizeof(nxt));
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s[x]++;
  }
  for (int i = N - 2; i >= 0; i--) nxt[i] = s[i] ? i : nxt[i + 1];
  for (int i = 1; i < N; i++) {
    pre[i] = s[i] ? i : pre[i - 1];
    s[i] += s[i - 1];
  }
  long long ans = 0;
  auto valid = [&](int x, int y) {
    if (x > 1 && y > 1) ans = max(ans, 1LL * x * y);
  };
  for (int y = 2; y < N; y++) {
    long long cnt = 0;
    for (int k = 1; 1LL * y * (k + 1) < N; k++)
      cnt += 1LL * k * sum(y * k, y * (k + 1) - 1);
    int a = -1, b = -1;
    auto con = [&](int x) {
      x %= y;
      if (x > a) swap(a, x);
      if (x > b) swap(b, x);
    };
    if (cnt)
      for (int k = N / y; k >= 0; k--)
        if (1LL * y * (k + 1) < N) {
          int x = pre[y * (k + 1) - 1];
          if (x >= y * k) {
            con(x);
            if (sum(x, x) == 1) x = pre[x - 1];
            if (x >= y * k) con(x);
          }
          if (2 * (cnt - k) >= k * y && a >= 0) {
            if (cnt - k >= (a + k * y) / 2)
              valid(y, (a + k * y) / 2);
            else
              valid(y, (cnt - k));
          }
          if (cnt - 2 * k >= k * y && b >= 0) {
            if (cnt - 2 * k >= b + k * y)
              valid(y, b + k * y);
            else
              valid(y, cnt - 2 * k);
          }
          if (a >= 0 && a + k * y >= 1 && sum(a + k * y, N - 1) > 1) {
            if (cnt - 2 * k - 1 >= a + k * y)
              valid(y, a + k * y);
            else
              valid(y, cnt - 2 * k - 1);
          }
        }
  }
  cout << ans << endl;
  return 0;
}
