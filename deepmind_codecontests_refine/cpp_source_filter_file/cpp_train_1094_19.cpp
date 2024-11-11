#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N];
double ans[N];
long long pre[N];
double ed;
int id, len;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
  if (n <= 2) return 0 * printf("1\n%d\n", a[1]);
  for (int i = 2; i <= n - 1; i++) {
    auto s = [&](int len) {
      return pre[n] - pre[n - len] + pre[i] - pre[i - 1 - len];
    };
    int l = 1, r = min(i - 1, n - i);
    while (l < r) {
      int lm = (l + l + r) / 3;
      int rm = (r + r + l + 2) / 3;
      long long s1 = s(lm);
      long long s2 = s(rm);
      if (s1 * (rm * 2 + 1) >= s2 * (lm * 2 + 1)) {
        r = rm - 1;
      } else {
        l = lm + 1;
      }
    }
    ans[i] = (1.0 * s(l) + a[i]) / (2 * l + 1) - a[i];
    if (ans[i] > ed) {
      ed = ans[i], len = l, id = i;
    }
  }
  cout << len * 2 + 1 << endl;
  if (len == 0) return 0 * (printf("%d\n", a[1]));
  for (int i = id - 1; i > id - 1 - len; i--) cout << a[i] << ' ';
  cout << a[id];
  for (int i = n; i > n - len; i--) cout << ' ' << a[i];
}
