#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
const long long K = 40;
set<long long> s;
long long a[N], n, mx;
void addx(long long x) { s.insert(x); }
long long query(long long k) {
  long long x;
  for (long long i = 0; i < (K); ++i) x |= (1 << i);
  x ^= k;
  long long y = 0;
  for (long long i = (K)-1; i >= 0; i--) {
    long long f = (x >> i) & 1;
    long long p = y + (f << i);
    if (s.lower_bound(p) == s.end() || (p >> i) != ((*s.lower_bound(p)) >> i))
      f ^= 1;
    y += (f << i);
  }
  return y;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (long long i = 0; i < (n); ++i) cin >> a[i];
  for (long long i = 0; i < (n - 1); ++i) a[i + 1] ^= a[i];
  mx = 0;
  addx(0);
  for (long long i = (n)-1; i >= 0; i--) {
    long long k = a[i];
    long long t = query(k);
    mx = max(mx, k ^ t);
    if (i != 0) {
      a[i] ^= a[i - 1];
    }
    if (i != n - 1) a[i] ^= a[i + 1];
    addx(a[i]);
  }
  long long tmp = query(0);
  mx = max(mx, tmp);
  cout << mx << endl;
}
