#include <bits/stdc++.h>
using std::cin;
using std::cout;
const int maxn = 1000003, INF = 0x3f3f3f3f, mod = 1e9 + 7;
typedef int arr[maxn];
arr a, l, r, stk;
int main() {
  std::ios::sync_with_stdio(0);
  cin.tie(0);
  int n, K;
  cin >> n >> K;
  for (int i = (1); i <= (n); ++i) cin >> a[i];
  int top = 0;
  for (int i = (1); i <= (n); ++i) {
    while (top > 0 && a[stk[top]] < a[i]) --top;
    l[i] = stk[top] + 1;
    stk[++top] = i;
  }
  stk[top = 0] = n + 1;
  for (int i = (n); i >= (1); --i) {
    while (top > 0 && a[stk[top]] < a[i]) --top;
    r[i] = stk[top] - 1;
    stk[++top] = i;
  }
  long long ans = 0;
  for (int i = (1); i <= (n); ++i) {
    if (i - l[i] < r[i] - i) {
      for (int j = (l[i]); j <= (i); ++j) {
        int mn = std::max(i - j, K - 1), mx = r[i] - j + 1;
        (ans += (long long)((mx - 1) / (K - 1) - (mn - 1) / (K - 1)) * a[i] %
                mod) %= mod;
      }
    } else {
      for (int j = (r[i]); j >= (i); --j) {
        int mn = std::max(j - i, K - 1), mx = j - l[i] + 1;
        (ans += (long long)((mx - 1) / (K - 1) - (mn - 1) / (K - 1)) * a[i] %
                mod) %= mod;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
