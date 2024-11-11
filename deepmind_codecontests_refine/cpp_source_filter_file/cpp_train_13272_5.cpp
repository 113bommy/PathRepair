#include <bits/stdc++.h>
using namespace std;
int bs(int space, int a, int n) {
  int lo = 0, hi = 200000, mid, ret = 0;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (mid * a + mid - 1 <= space) {
      ret = max(ret, mid);
      lo = mid + 1;
    } else
      hi = mid - 1;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k, a, m, buf, cur, tmp;
  set<int> moves;
  cin >> n >> k >> a;
  cur = k;
  moves.insert(0);
  moves.insert(n + 1);
  cin >> m;
  while (m--) {
    cin >> buf;
    int x = *(moves.upper_bound(buf)), y = *(--moves.upper_bound(buf)), z = buf;
    moves.insert(buf);
    cur = max(0, cur - bs(x - y - 1, a, n));
    cur += bs(x - z - 1, a, n);
    cur += bs(z - y - 1, a, n);
    if (cur < k) {
      cout << moves.size() - 2;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
