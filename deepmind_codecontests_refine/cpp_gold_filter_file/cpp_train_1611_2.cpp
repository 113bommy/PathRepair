#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
  long long t, a, b, sol = 0;
  cin >> t >> a >> b;
  if (a == 1) {
    if (b != 1) {
      cout << "0\n";
      return 0;
    }
    if (t == 1) {
      cout << "inf\n";
    } else {
      cout << "1\n";
    }
    return 0;
  }
  vector<long long> v;
  for (long long x = b; x; x /= a) v.push_back(x % a);
  long double tr = 0;
  unsigned long long ti = 0;
  for (int i = v.size() - 1; i >= 0; i--) {
    tr = tr * t + v[i];
    ti = ti * t + v[i];
  }
  if (tr < 2e18 && (long long)ti == a) sol++;
  if (t == 1) {
    long long q = b;
    while (q % a == 0) q /= a;
    if (q == 1 && b > 1) sol++;
  } else if (a == b)
    sol++;
  cout << sol << '\n';
}
