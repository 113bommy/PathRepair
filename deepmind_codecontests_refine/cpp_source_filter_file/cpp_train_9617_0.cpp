#include <bits/stdc++.h>
using namespace std;
struct BIT {
  long long n;
  vector<long long> bit;
  BIT() {}
  BIT(long long _) : n(_) { bit.assign(n + 1, 0); }
  void add(long long i, long long u) {
    for (; i <= n; i += (i & -i)) bit[i] += u;
  }
  long long sum(long long i) {
    long long res = 0;
    for (; i > 0; i -= (i & -i)) res += bit[i];
    return res;
  }
};
struct BITRange {
  long long n;
  BIT bit1;
  BIT bit2;
  BITRange(long long _) : n(_) {
    bit1 = BIT(n);
    bit2 = BIT(n);
  }
  void add(long long l, long long r, long long u) {
    bit1.add(l, u);
    bit1.add(r + 1, -u);
    bit2.add(l, (l - 1) * u);
    bit2.add(r + 1, -r * u);
  }
  long long pref_sum(long long i) { return i * bit1.sum(i) - bit2.sum(i); }
  long long sum(long long l, long long r) {
    return pref_sum(r) - pref_sum(l - 1);
  }
};
int main() {
  cout << fixed << setprecision(10);
  long long n;
  cin >> n;
  BITRange bit(n);
  long long len = 1;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      long long a, x;
      cin >> a >> x;
      bit.add(1, a, x);
    } else if (t == 2) {
      long long k;
      cin >> k;
      bit.add(len + 1, len + 1, k);
      len++;
    } else {
      bit.add(len, len, -bit.sum(len, len));
      len--;
    }
    cout << bit.sum(1, len) / (long double)(len) << '\n';
  }
  return 0;
}
