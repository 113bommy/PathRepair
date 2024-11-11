#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int equ[2 * maxn], cover[2 * maxn], a[maxn];
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    fill(equ, equ + 2 * k + 5, 0);
    fill(cover, cover + 2 * k + 5, 0);
    for (int i = 1; i <= n / 2; i++) equ[a[i] + a[n - i + 1]]++;
    for (int i = 1; i <= n / 2; i++) {
      cover[min(a[i], a[n - i + 1]) + 1]++;
      cover[max(a[i], a[n - i + 1]) + k + 1]--;
    }
    for (int i = 3; i <= 2 * k; i++) cover[i] += cover[i - 1];
    int ans = INT_MAX;
    for (int x = 2; x <= 2 * k; x++)
      ans = min(ans, cover[x] - equ[x] + (n / 2 - cover[x]) * 2);
    printf("%d\n", ans);
  }
  return 0;
}
