#include <bits/stdc++.h>
using namespace std;
const int N = 4e6 + 7;
int n, a[N], vis[N], q, num[N];
vector<int> magh[N];
void pre(int ind, int x) {
  for (int i = 1; i < (1 << (((int)magh[ind].size()))); i++) {
    int mul = 1;
    for (int j = 0; j <= 7; j++) mul *= ((i & (1 << j)) ? magh[ind][j] : 1);
    num[mul] += x;
    if (0) cerr << a[ind] << ' ' << mul << '\n';
  }
}
int calc(int x) {
  int ans = 0;
  for (int i = 1; i < (1 << (((int)magh[x].size()))); i++) {
    int mul = 1;
    for (int j = 0; j <= 7; j++) mul *= ((i & (1 << j)) ? magh[x][j] : 1);
    if (__builtin_popcount(i) % 2)
      ans += num[mul];
    else
      ans -= num[mul];
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int x = a[i];
    for (int j = 2; j * j <= x; j++)
      if (!(x % j)) {
        magh[i].push_back(j);
        while (!(x % j)) x /= j;
      }
    if (x - 1) magh[i].push_back(x);
  }
  int ans = 0, sum = 0;
  while (q--) {
    int x;
    cin >> x;
    x--;
    if (vis[x]) {
      sum--;
      pre(x, -1);
      ans -= (sum - calc(x));
      if (0) cerr << calc(x) << '\n';
    } else {
      ans += (sum - calc(x));
      if (0) cerr << calc(x) << '\n';
      sum++;
      pre(x, 1);
    }
    vis[x] ^= 1;
    cout << ans << '\n';
  }
}
