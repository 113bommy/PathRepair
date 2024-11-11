#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
vector<int> v[100010];
int n, m, now, ans;
int a[100010];
bool flag;
int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
int dfs(int x, int f) {
  if (flag) return 0;
  int sum = v[x].size();
  for (int i = 0; i < v[x].size(); i++)
    if (v[x][i] != f) sum -= dfs(v[x][i], x);
  if (sum % now && (sum - 1) % now) {
    ans = 1;
    flag = true;
    return 0;
  }
  if (sum % now == 0) {
    ans = gcd(ans, sum);
    return 1;
  }
  ans = gcd(ans, sum - 1);
  return 0;
}
int main() {
  int t, x, y;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
      scanf("%d%d", &x, &y);
      v[x].push_back(y);
      v[y].push_back(x);
    }
    m = n - 1;
    for (now = 2; now <= sqrt(m); now++)
      if (m % now == 0) {
        ans = 0;
        flag = 0;
        dfs(1, -1);
        a[ans] = 1;
        while (m % now == 0) m /= now;
      }
    if (m > 1) {
      ans = 0;
      flag = 0;
      now = m;
      dfs(1, -1);
      a[ans] = 1;
    }
    a[1] = 1;
    for (int i = 1; i <= m; i++) a[1] = a[1] * 2 % mod;
    for (int i = 2; i <= m; i++) a[1] = (a[1] - a[i] + mod) % mod;
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    printf("\n");
    for (int i = 1; i <= n; i++) v[i].clear(), a[i] = 0;
  }
}
