#include <bits/stdc++.h>
using namespace std;
const int Maxn = 10000010;
const int INF = 0x7f7f7f7f;
const double eps = 1e-8;
const double pi = 3.1415926535897932384626433832795;
struct Item {
  int l, r, id;
  bool operator<(const Item &t) const {
    if (l == t.l) return r < t.r;
    return l < t.l;
  }
};
Item it[110];
bool used[Maxn];
int main() {
  int n;
  int ans[110];
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> it[i].l >> it[i].r;
    it[i].id = i;
  }
  sort(it + 1, it + n + 1);
  for (int i = 1; i <= n; i++) {
    int t = it[i].l;
    while (used[t]) t++;
    used[t] = 1;
    ans[it[i].id] = t;
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  return 0;
}
