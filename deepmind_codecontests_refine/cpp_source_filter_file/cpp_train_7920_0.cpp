#include <bits/stdc++.h>
using namespace std;
const int MAX = 37;
const int MOD = 1000000007;
int query(int val) {
  cout << val << endl;
  int res;
  cin >> res;
  return res;
}
void solve() {
  int m, n;
  cin >> m >> n;
  int a[MAX];
  for (int i = 0; i < n; i++) {
    a[i] = -query(1);
    if (a[i] == 0) {
      return;
    } else if (a[i] == 2) {
      return;
    }
  }
  int l = 1, r = m, cnt = 0;
  while (l + 1 < r) {
    int mid = (l + r + 1) / 2;
    int res = query(mid) * a[cnt];
    if (res == 0) {
      return;
    } else if (res == 1) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
    cnt++;
    cnt %= n;
  }
  query(r);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}
