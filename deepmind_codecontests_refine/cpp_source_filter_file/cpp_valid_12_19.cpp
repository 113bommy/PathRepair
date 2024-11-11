#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
ostream& operator<<(ostream& out, const pair<A, B>& a) {
  return out << "(" << a.first << ", " << a.second << ")";
}
template <class A>
ostream& operator<<(ostream& out, const vector<A>& v) {
  out << "[";
  for (int i = 0; i < int(int(v.size())); i++) {
    if (i) out << ", ";
    out << v[i];
  }
  return out << "]";
}
mt19937 rnd(time(NULL));
const int INF = int(1e9);
const long long INF64 = long long(1e18);
const int MOD = int(1e9) + 7;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);
int n, m, k;
bool read() {
  if (scanf("%d%d%d", &n, &m, &k) != 3) return false;
  return true;
}
void solve() {
  if (m % 2) --m;
  if (n % 2) k -= m / 2, --n;
  if (k < 0 || k % 2 == 1 || k > n * m) {
    puts("NO");
    return;
  }
  puts("YES");
}
int main() {
  cerr.precision(15);
  cout.precision(15);
  cerr << fixed;
  cout << fixed;
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    read();
    solve();
  }
}
