#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 * 1005;
int n, a[3 * maxn], m, fact[3 * maxn];
long long list[2 * maxn];
int main() {
  cin >> n;
  int i, j;
  int ans = 1;
  int drop = 0;
  for (i = 1; i <= 2 * n; ++i) {
    cin >> a[i];
    if (i > n && a[i - n] == a[i]) drop++;
  }
  cin >> m;
  sort(a + 1, a + 2 * n + 1);
  fact[1] = 1;
  fact[0] = 1;
  int cnt = 0;
  for (i = 1; i <= 2 * n + 1; ++i) {
    if (a[i] != a[i - 1]) {
      for (j = 1; j <= cnt; ++j) {
        int aux = j;
        while (drop && aux % 2 == 0) {
          aux /= 2;
          drop--;
        }
        ans = 1LL * ans * aux;
      }
      cnt = 1;
    } else {
      cnt++;
    }
  }
  cout << ans << "\n";
  return 0;
}
