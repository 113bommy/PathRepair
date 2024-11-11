#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
inline ostream& operator<<(ostream& os, const pair<A, B>& v) {
  return os << v.first << ' ' << v.second;
}
template <typename A>
inline ostream& operator<<(ostream& os, const vector<A>& v) {
  auto it = v.begin();
  os << *it;
  for (++it; it != v.end(); os << ' ' << *it++)
    ;
  return os;
}
void W() { cout << endl; }
template <typename H, typename... T>
inline void W(H head, T... tail) {
  cout << head << ' ';
  W(tail...);
}
const double eps = 1e-9, PI = acos(-1);
const long long mod = (long long)1e9 + 7;
const int oo = 0x3f3f3f3f;
mt19937 rnd((unsigned long long)time(0));
long long pow_mod(long long a, long long b) {
  assert(b >= 0);
  long long res = 1;
  for (a %= mod; b; b >>= 1, a = a * a % mod)
    if (b & 1) res = res * a % mod;
  return res;
}
void solve();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}
const long long add = 49;
long long n;
set<int> s;
inline long long count(int n = 20) {
  for (int a = 0; a <= n; a++)
    for (int b = 0; a + b <= n; b++)
      for (int c = 0; a + b + c <= n; c++) {
        int d = n - a - b - c;
        s.insert(a + 5 * b + 10 * c + 50 * d);
      }
  return ((int)(s).size());
}
void solve() {
  cin >> n;
  if (n <= 12) {
    cout << count(n) << endl;
    return;
  }
  cout << add * (n - 12) + count();
  return;
}
