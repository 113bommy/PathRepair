#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, m;
struct node {
  int l, r;
  bool operator<(const node &x) const {
    if (r - l + 1 == x.l - x.r + 1) {
      return l > x.l;
    }
    return r - l + 1 < x.r - x.l + 1;
  }
};
int a[maxn];
void solve() {
  priority_queue<node> q;
  cin >> n;
  q.push(node{1, n});
  for (int i = 1; i <= n; i++) {
    node m = q.top();
    q.pop();
    int l = m.l;
    int r = m.r;
    a[(l + r) / 2] = i;
    int mid = ((l + r) >> 1);
    if (l <= mid - 1) {
      q.push(node{l, mid - 1});
    }
    if (mid + 1 <= r) {
      q.push(node{mid + 1, r});
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << " \n"[i == n];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
