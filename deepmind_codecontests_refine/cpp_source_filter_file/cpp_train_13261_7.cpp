#include <bits/stdc++.h>
using namespace std;
const int N = 4e6 + 10;
const long long mod = 998244353;
struct node {
  int l, r, id;
} q[N];
int a[N];
int pos[N];
int tr[N];
int p[N];
int lowbit(int x) { return x & -x; }
void add(int x, int c) {
  int i;
  for (i = x; i < N; i += lowbit(i)) {
    tr[i] += c;
  }
}
int sum(int x) {
  int i;
  int ans = 0;
  for (i = x; i; i -= lowbit(i)) {
    ans += tr[i];
  }
  return ans;
}
bool cmp(node a, node b) { return a.r < b.r; }
vector<int> num[N];
int ans[N];
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int i;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  for (i = 1; i <= m; i++) {
    cin >> q[i].l >> q[i].r;
    q[i].id = i;
  }
  sort(q + 1, q + 1 + m, cmp);
  int cur = 1;
  for (i = 1; i <= n; i++) {
    int tmp = a[i];
    for (auto x : num[tmp]) {
      add(x, 1);
    }
    for (int j = i; j <= n; j += tmp) {
      int d = pos[j];
      if (d <= i) {
        add(d, 1);
      } else {
        num[j].push_back(i);
      }
    }
    while (cur <= m && q[cur].r == i) {
      ans[q[cur].id] = sum(q[cur].r) - sum(q[cur].l - 1);
      cur++;
    }
  }
  for (i = 1; i <= m; i++) {
    cout << ans[i] << endl;
  }
}
