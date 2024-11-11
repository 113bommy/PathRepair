#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 10;
long long n, m, h[maxn], tr[maxn];
bool ok(long long l) {
  long long p1 = 0, p2 = 0;
  while (p1 < n && p2 < m) {
    if (h[p1] <= tr[p2]) {
      while (p2 < m && tr[p2] <= h[p1] + l) p2++;
      p1++;
      continue;
    }
    long long pp1 = p2, pp2 = p2;
    if (h[p1] - tr[p2] > l) return false;
    while (pp1 < m && tr[pp1] <= max(h[p1], l - h[p1] + (tr[p2] * 2))) pp1++;
    while (pp2 < m && tr[pp2] <= (l + h[p1] + tr[p2]) / 2) pp2++;
    p2 = max(pp1, pp2);
    p1++;
  }
  return (p2 == m ? true : false);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> h[i];
  for (int i = 0; i < m; i++) cin >> tr[i];
  long long l = 0, r = (long long)2e10 + 1, ans;
  while (l <= r) {
    bool f;
    long long mid = (l + r) / 2;
    f = ok(mid);
    if (f) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << ans;
}
