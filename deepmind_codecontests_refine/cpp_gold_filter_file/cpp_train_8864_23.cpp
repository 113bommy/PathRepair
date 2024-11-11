#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 999;
struct node {
  int l, r;
  bool operator<(const node& n) const { return l < n.l; }
};
node ori[maxn];
int aft[maxn][33];
int f[maxn];
void init() {
  f[0] = 1;
  for (int i = 1; i <= 30; i++) f[i] = f[i - 1] * 2;
}
void solve() {
  init();
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &ori[i].l, &ori[i].r);
    ori[i].l++;
    ori[i].r++;
  }
  sort(ori + 1, ori + 1 + n);
  int R = maxn - 90;
  int arr = 1;
  int nowr = 0;
  for (int i = 1; i <= R; i++) {
    while (arr <= n && ori[arr].l <= i) {
      nowr = max(nowr, ori[arr].r);
      arr++;
    }
    aft[i][0] = max(i, nowr);
  }
  for (int i = R; i >= 1; i--) {
    for (int j = 1; j <= 20; j++) {
      aft[i][j] = aft[aft[i][j - 1]][j - 1];
    }
  }
  for (int i = 1; i <= m; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    l++;
    r++;
    int ans = 0;
    for (int j = 20; j >= 0; j--) {
      if (aft[l][j] < r) {
        ans += f[j];
        l = aft[l][j];
      }
    }
    ans++;
    if (ans > n) ans = -1;
    cout << ans << endl;
  }
}
signed main() { solve(); }
