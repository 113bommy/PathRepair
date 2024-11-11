#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, m, x, k, y;
vector<long long> a, b, pos;
long long destroy(long long lx, long long rx) {
  if (lx > rx) return 0;
  long long torem = rx - lx + 1;
  long long maxi = 0, maxpos, lhs = max((long long)0, lx - 1),
            rhs = min(rx + 1, n - 1);
  for (long long i = lhs; i <= rhs; i++) {
    if (maxi > a[i]) {
      maxi = a[i];
      maxpos = i;
    }
  }
  long long ans = pow(10, 18);
  long long p = torem / k;
  bool con = (maxpos >= lx && maxpos <= rx);
  long long start;
  if (con)
    start = 1;
  else
    start = 0;
  for (long long i = start; i <= p; i++) {
    long long cost = i * x + y * (torem - i * k);
    ans = min(ans, cost);
  }
  if (con && torem < k) return -1;
  return ans;
}
void aksayushx() {
  cin >> n >> m;
  cin >> x >> k >> y;
  a.resize(n);
  b.resize(m);
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < m; i++) cin >> b[i];
  long long look = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] == b[look]) {
      pos.push_back(i);
      look++;
    }
    if (look >= m) break;
  }
  long long ans = 0, len = pos.size() - 1;
  if (pos.size() < m) {
    cout << -1;
    return;
  }
  if (pos[0] != 0) ans += destroy(0, pos[0] - 1);
  bool ok = true;
  if (ans == -1) ok = false;
  for (long long i = 0; i < len; i++) {
    long long cost = destroy(pos[i] + 1, pos[i + 1] - 1);
    ans += cost;
    if (cost == -1) {
      ok = false;
      break;
    }
  }
  if (pos[len] != n - 1) {
    long long cost = destroy(pos[len] + 1, n - 1);
    ans += cost;
    if (cost == -1) ok = false;
  }
  if (!ok)
    cout << -1;
  else
    cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) aksayushx();
  return 0;
}
