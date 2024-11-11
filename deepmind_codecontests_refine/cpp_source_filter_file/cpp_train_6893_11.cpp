#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
void accell() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
}
long long ask(long long x) {
  cout << "? ";
  cout << x + 1 << endl;
  char c;
  cin >> c;
  if (c == 'Y')
    return 0;
  else
    return 1;
}
void clean() {
  cout << "R" << endl;
  return;
}
signed main() {
  accell();
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n, 1);
  for (long long i = 0; i < n; ++i) {
    a[i] &= ask(i);
  }
  clean();
  long long d = max(k / 2, 1LL);
  for (long long i = d; i < (n / d); i += d) {
    for (long long j = 0; j + d < i; j += d) {
      for (long long c = j; c < j + d; ++c) a[c] &= ask(c);
      for (long long c = i; c < i + d; ++c) a[c] &= ask(c);
      clean();
    }
  }
  long long res = 0;
  for (long long i = 0; i < n; ++i) res += a[i];
  cout << "! " << res << endl;
  return 0;
}
