#include <bits/stdc++.h>
using namespace std;
int dir8[8][2] = {{1, 0}, {0, 1},  {-1, 0}, {0, -1},
                  {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int dir4[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
const int INF = 0x3f3f3f3fLL;
const long long LLF = 0x3f3f3f3f3f3f3f3fLL;
const int MAXn = 1e5 + 15;
const int mod = 1e9 + 7;
long long a[MAXn], b[MAXn];
long long s[MAXn], mi[MAXn];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  mi[0] = LLF;
  for (int i = 1; i <= n; i++) {
    mi[i] = min(mi[i - 1], b[i]);
  }
  for (int i = n; i; --i) s[i] = s[i + 1] + a[i];
  long long ans = 0;
  if (k == 0) {
    for (int i = 1; i <= n; i++) {
      ans = max(ans, s[i] - b[i]);
    }
  } else if (k > 1) {
    for (int i = 2; i <= n; i++)
      ans = max({ans, s[1] - mi[n - 1], a[n] - b[n]});
  } else {
    for (int i = 2; i <= n; i++)
      ans = max(ans, max((long long)0, a[1] - a[i] - mi[i - 1]) +
                         max((long long)0, a[i] - b[i]));
    for (int i = 1; i < n - 1; i++)
      ans = max(
          ans, s[1] - a[1 + i] - b[1] + max((long long)0, a[i + 1] - b[i + 1]));
  }
  cout << ans << endl;
  return 0;
}
