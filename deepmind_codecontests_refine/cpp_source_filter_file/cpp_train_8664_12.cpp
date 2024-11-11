#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1), eps = 1e-8;
const int maxn = 1 << 17;
const int N = 2e5 + 10, M = 1e6 + 10, mod = 1e9 + 7;
int n, m;
int l[N];
long long s;
int ans[N];
int main() {
  cin >> n >> m;
  int now = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &l[i]);
    s += l[i];
  }
  s -= l[m];
  n -= l[m];
  if (s < n || m - 1 > n) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i < m; i++) {
    s -= l[i];
    if (now + l[i] > n) {
      cout << -1;
      return 0;
    }
    if (s + 1 >= n - now) {
      l[i] = 1;
    } else {
      l[i] = n - now - s;
    }
    ans[i] = now + 1;
    now += l[i];
  }
  ans[m] = now + 1;
  for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
  return 0;
}
