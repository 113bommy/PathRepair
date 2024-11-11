#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
long long powm(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % 998244353;
    a = (a * a) % 998244353;
    b >>= 1;
  }
  return res;
}
long long Index(vector<long long> &a, long long l, long long r, long long key) {
  while (r - l > 1) {
    long long mid = l + (r - l) / 2;
    if (a[mid] > key)
      r = mid;
    else
      l = mid;
  }
  return r;
}
long long solve(vector<long long> &a) {
  if ((long long)a.size() == 0) return 0;
  vector<long long> tail((long long)a.size(), 0);
  long long len = 1;
  tail[0] = a[0];
  for (long long i = 1; i < (long long)a.size(); i++) {
    if (a[i] < tail[0])
      tail[0] = a[i];
    else if (a[i] >= tail[len - 1])
      tail[len++] = a[i];
    else
      tail[Index(tail, -1, len - 1, a[i])] = a[i];
  }
  return len;
}
signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  vector<long long> b(m);
  for (long long i = 0; i < m; i++) cin >> b[i];
  map<long long, long long> mm, vis;
  long long f = 1;
  for (long long i = 0; i < n; i++) {
    mm[i + 1] = a[i];
  }
  vector<long long> arr;
  for (long long i = 0; i < m; i++) {
    vis[b[i]] = 1;
    arr.push_back(mm[b[i]]);
    if (i + 1 < m) {
      if (mm[b[i + 1]] - mm[b[i]] < b[i + 1] - b[i]) {
        f = 0;
        break;
      }
    }
  }
  if (!f) {
    cout << "-1" << '\n';
    return 0;
  }
  for (long long i = 0; i < n; i++) {
    a[i] = a[i] - i;
  }
  long long ans = 0, ind = 0, prev_ind = -1, prev_val = 0;
  for (long long i = 0; i < m; i++) {
    vector<long long> c;
    long long j = b[i] - 1, d = 0, val = a[j];
    while (ind < j) {
      d++;
      if (a[ind] <= val && a[ind] >= prev_val) {
        c.push_back(a[ind]);
      }
      ind++;
    }
    prev_val = val;
    prev_ind = j;
    ind = j + 1;
    long long rem = solve(c);
    ans += d - rem;
  }
  vector<long long> c;
  long long j = n, d = 0, val = -INF;
  if (m > 0) val = a[b[m - 1] - 1];
  while (ind < j) {
    d++;
    if (a[ind] >= val) {
      c.push_back(a[ind]);
    }
    ind++;
  }
  long long rem = solve(c);
  ans += d - rem;
  cout << ans << '\n';
}
