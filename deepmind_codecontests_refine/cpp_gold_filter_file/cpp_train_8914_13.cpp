#include <bits/stdc++.h>
using namespace std;
template <class U, class V>
ostream& operator<<(ostream& os, const pair<U, V>& p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
template <class U, class V>
istream& operator>>(istream& in, pair<U, V>& p) {
  in >> p.first >> p.second;
  return in;
}
const long long N = 1e6;
long long t[2 * N], sz;
void build() {
  for (long long i = 0; i < 2 * N; i++) {
    t[i] = -1;
  }
}
long long query(long long l, long long r) {
  long long res = -1;
  for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = max(res, t[l++]);
    if (r & 1) res = max(res, t[--r]);
  }
  return res;
}
void modify(long long p, long long v) {
  if (t[p + sz] < v) {
    for (t[p += sz] = v; p > 1; p >>= 1) {
      t[p >> 1] = max(t[p ^ 1], t[p]);
    }
  }
}
int main() {
  long long n;
  scanf("%lld", &n);
  ;
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
    ;
  }
  set<long long> s(arr, arr + n);
  sz = s.size();
  build();
  map<long long, long long> m;
  vector<long long> v(s.begin(), s.end());
  for (long long i = 0; i < sz; i++) {
    m[v[i]] = i;
  }
  long long res[n];
  for (long long i = n - 1; i >= 0; i--) {
    long long q = query(0, m[arr[i]]);
    res[i] = -1;
    if (q != -1) {
      res[i] = q - i - 1;
    }
    modify(m[arr[i]], i);
  }
  for (long long i = 0; i < n; i++) {
    cout << res[i] << ' ';
  }
  cout << endl;
  return 0;
}
