#include <bits/stdc++.h>
using namespace std;
const long long N = 2 * 1000 + 10,
                INF = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;
long long n, k, p;
long long ky[N], pl[N];
long long dis(int ind, int i) {
  return abs(ky[ind] - pl[i]) + abs(p - ky[ind]);
}
bool ok(long long mid) {
  int ind = 0;
  for (int i = 0; i < n; i++) {
    while (ind < k && dis(ind, i) > mid) ind++;
    if (ind == k) return false;
    ind++;
  }
  return true;
}
long long bs(long long s, long long e) {
  if (e - s <= 1) return e;
  long long mid = (s + e) / 2;
  if (ok(mid))
    return bs(s, mid);
  else
    return bs(mid, e);
}
int main() {
  cin >> n >> k >> p;
  for (int i = 0; i < n; i++) cin >> pl[i];
  for (int i = 0; i < k; i++) cin >> ky[i];
  sort(pl, pl + n);
  sort(ky, ky + k);
  cout << bs(0, INF) << endl;
}
