#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int n = 0, c = 0, m;
  while (!isdigit(c)) m = c - 45 ? 1 : -1, c = getchar();
  while (isdigit(c)) n = n * 10 + c - 48, c = getchar();
  return m * n;
}
const int N = 70001;
int a[N], b[N];
int main() {
  int n = read(), k = read(), p = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= k; i++) b[i] = read();
  sort(a + 1, a + n + 1);
  sort(b + 1, b + k + 1);
  int ans = 4000 * 1000 * 1000;
  for (int i = 1; i + n - 1 <= k; i++) {
    int mx = 0, cur = 1;
    for (int j = i; j <= i + n - 1; j++, cur++) {
      mx = max(mx, abs(a[cur] - b[j]) + abs(b[j] - p));
    }
    ans = min(ans, mx);
  }
  cout << ans;
}
