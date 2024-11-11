#include <bits/stdc++.h>
constexpr long long inf = 1e18 + 7, base = 541, mod = 1e9 + 7;
constexpr long long N = 4e6 + 7;
using namespace std;
long long n, mx[N], flg[N], a[N], seg[N];
void build(long long s = 0, long long e = n + 1, long long tag = 1) {
  if (s == n - 1) mx[tag] = a[s];
  long long mid = (s + e) / 2;
  build(s, mid, tag * 2);
  build(mid, e, tag * 2 + 1);
}
long long Query(long long s = 0, long long e = n + 1, long long tag = 1) {
  if (e - 1 == s) {
    mx[tag] = -inf;
    return a[s];
  }
  long long q, mid = (s + e) / 2;
  if (mx[tag * 2] > mx[tag * 2 + 1])
    q = Query(s, mid, tag * 2);
  else
    q = Query(mid, e, tag * 2 + 1);
  mx[tag] = max(mx[tag * 2], mx[tag * 2 + 1]);
  return q + flg[tag];
}
void Update(long long l, long long r, long long q, long long s = 0,
            long long e = n + 1, long long tag = 1) {
  if (r <= s || l >= e) return;
  if (r <= e && l >= s) {
    flg[tag] += q;
    mx[tag] += q;
    return;
  }
  long long mid = (s + e) / 2;
  Update(l, r, q, s, mid, tag * 2);
  Update(l, r, q, mid, e, tag * 2 + 1);
}
long long arr[N], num[N];
bool cmd(long long x, long long y) { return num[x] < num[y]; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (long long(i) = (0); (i) < (n); ++(i))
    cin >> a[i], num[i] = a[i] - n, arr[i] = i;
  sort(arr, arr + n, cmd);
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    if (-i + arr[i] + a[arr[i]] >= 0)
      v.push_back(-i + arr[i] + a[arr[i]]);
    else {
      cout << ":(\n";
      return 0;
    }
  }
  for (long long(i) = (0); (i) < (n - 1); ++(i))
    if (v[i] > v[i + 1]) {
      cout << ":(\n";
      return 0;
    }
  for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
    cout << *i << ' ';
}
