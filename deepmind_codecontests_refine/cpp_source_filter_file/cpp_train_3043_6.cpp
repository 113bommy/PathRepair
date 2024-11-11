#include <bits/stdc++.h>
const int maxn = 2e5 + 10;
const int maxm = 1e5 + 10;
const long long int mod = 1e9 + 7;
const long long int INF = 1e18 + 100;
const int inf = 0x3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-8;
using namespace std;
int n, m;
int cas, tol, T;
int get(int x) {
  x--;
  int pre = 1, ans = 0;
  for (int i = 1; x; i++) {
    pre *= 2;
    ans += min(pre, x) * i;
    if (x >= pre)
      x -= pre;
    else
      x = 0;
  }
  return ans;
}
vector<int> vec[maxn];
int fa[maxn];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    if (m > n * (n - 1) / 2 || m < get(n)) {
      printf("NO\n");
      continue;
    }
    for (int i = 0; i < n; i++) vec[i].clear();
    memset(fa, 0, sizeof fa);
    int now = n * (n - 1) / 2, pos = 1, l = 1, r = n - 1, flag = 1;
    vec[0].push_back(1);
    while (now > m && flag) {
      if (l > r) {
        flag = 0;
        break;
      }
      if (now - r + l >= m) {
        now -= (r - l);
        pos++;
        r--;
        vec[l].push_back(pos);
        if (vec[l].size() == (1 << l) - 1) l++;
      } else {
        pos++;
        vec[r - (now - m)].push_back(pos);
        r--;
        now = m;
      }
    }
    if (!flag) {
      printf("NO\n");
      continue;
    }
    printf("YES\n");
    for (int i = pos + 1; i <= n; i++, r--) {
      vec[r].push_back(i);
    }
    for (int i = 1; vec[i].size(); i++) {
      int len = vec[i].size();
      for (int j = 0; j < len; j++) {
        fa[vec[i][j]] = vec[i - 1][j / 2];
      }
    }
    for (int i = 2; i <= n; i++) {
      printf("%d%c", fa[i], i == n ? '\n' : ' ');
    }
  }
  return 0;
}
