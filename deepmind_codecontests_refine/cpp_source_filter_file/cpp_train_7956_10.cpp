#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long maxn = 3e6;
const long long mod = 1e9 + 7;
const long double PI = acos((long double)-1);
long long pw(long long a, long long b, long long md = mod) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = (a * res) % md;
    }
    a = (a * a) % md;
    b >>= 1;
  }
  return (res);
}
int ans[maxn], mark[maxn];
int cnt = 2e6;
int n, m;
struct Tree {
  int sz = 0, bit[maxn];
  int size() { return sz; }
  void update(int k, int x) {
    while (k < maxn) {
      bit[k] += x;
      k += k & -k;
    }
    sz += x;
  }
  int find_by_order(int k) {
    int ans = 0, sum = 0;
    for (int j = 30; j >= 0; --j) {
      ans += 1 << j;
      if (ans < maxn && sum + bit[ans] < k) {
        sum += bit[ans];
      } else {
        ans -= 1 << j;
      }
    }
    return ans + 1;
  }
  int order_of_key(int k) {
    k++;
    int ans = 0;
    while (k >= 1) {
      ans += bit[k];
      k -= k & -k;
    }
    return ans - 1;
  }
} pbds;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) pbds.update(i + 2e6, 1);
  while (m--) {
    int x, pos;
    cin >> x >> pos;
    int i = pbds.find_by_order(pos);
    if (i > 2e6) {
      if (mark[x]) return (cout << -1, 0);
      ;
      ans[i] = x;
      mark[x] = 1;
      pbds.update(i, -1);
      pbds.update(cnt, 1);
      ans[cnt] = x;
      cnt--;
    } else {
      if (ans[i] != x) return (cout << -1, 0);
      ;
      pbds.update(i, -1);
      pbds.update(cnt, 1);
      ans[cnt] = x;
      cnt--;
    }
  }
  cnt = 1;
  for (int i = 1; i <= n; i++) {
    if (ans[i + 2000000]) {
      cout << ans[i + 2000000] << ' ';
      continue;
    }
    while (mark[cnt]) cnt++;
    cout << cnt << ' ';
    cnt++;
  }
  return (0);
}
