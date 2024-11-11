#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int val[N], ar[N];
bool canDoit(int n, int m, int mid) {
  int v = min(ar[n - 1] + mid, m);
  for (int i = n - 2; i >= 0; --i) {
    if (ar[i] <= v) {
      v = min(v, ar[i] + mid);
    } else {
      if (ar[i] + mid <= m) {
        return false;
      }
      int t = ar[i] + mid - m;
      t = min(t, v);
    }
  }
  return true;
}
void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &ar[i]);
    ++ar[i];
  }
  int l = 0, r = m - 1, mid;
  while (l < r) {
    mid = (l + r) / 2;
    if (canDoit(n, m, mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
}
int main() {
  solve();
  return 0;
}
