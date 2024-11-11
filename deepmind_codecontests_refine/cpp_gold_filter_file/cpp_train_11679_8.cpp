#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
const int maxn = (long long)1e5 + 5;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;
struct node {
  int l, r, d;
  bool operator<(const node &b) const { return d > b.d; }
} a[maxn];
int pos[maxn << 2];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    a[i].l = i * 2 - 1;
    a[i].r = i * 2;
    cin >> a[i].d;
  }
  int r = n, l = 1;
  sort(a + 1, a + n + 1);
  vector<pair<int, int>> ans;
  for (int i = 1; i <= n; ++i) {
    while (pos[l]) ++l;
    pos[l] = a[i].r;
    if (l + a[i].d == r + 1) {
      ++r;
      pos[r] = a[i].l;
    } else
      ans.push_back(make_pair(l + a[i].d - 1, a[i].l));
  }
  for (int i = 1; i < r; ++i) ans.push_back(make_pair(i, pos[i + 1]));
  for (auto &i : ans) cout << pos[i.first] << ' ' << i.second << '\n';
  return 0;
}
