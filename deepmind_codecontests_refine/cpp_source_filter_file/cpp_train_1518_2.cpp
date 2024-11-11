#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5 + 5, inf = 0x3f3f3f3f;
vector<int> e[maxn];
int n, m, t, k, a[maxn], f[maxn], cnt;
int main() {
  cin >> n >> t >> k;
  a[0] = 1;
  for (int i = 1; i <= t; i++) {
    cin >> a[i];
  }
  if (a[t] > t || n - t < k) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i <= t; i++) {
    for (int j = 1; j <= a[i]; j++) {
      e[i].push_back(++cnt);
    }
  }
  for (int i = 0; i < a[1]; i++) {
    f[e[1][i]] = 1;
  }
  for (int i = 2; i <= t; i++) {
    f[e[i][0]] = e[i - 1][0];
  }
  int res = n - k - t;
  for (int i = 2; i <= t; i++) {
    for (int j = 1; j < a[i]; j++) {
      if (res && j < a[i - 1]) {
        f[e[i][j]] = e[i - 1][j];
        res--;
      } else
        f[e[i][j]] = e[i - 1][0];
    }
  }
  if (res) {
    puts("-1");
    return 0;
  }
  cout << n << endl;
  for (int i = 2; i <= n; i++) {
    printf("%d %d\n", i, f[i]);
  }
  return 0;
}
