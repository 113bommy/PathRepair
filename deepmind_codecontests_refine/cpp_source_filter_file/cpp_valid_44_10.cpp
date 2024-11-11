#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const int MAX_N = 100011;
const long long INF = (1 << 29) + 123;
const long long MOD = 1000000007;
const long double PI = 4 * atan((long double)1);
template <typename T>
bool ckmin(T& a, const T& b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
bool ckmax(T& a, const T& b) {
  return b > a ? a = b, 1 : 0;
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << H << " ";
  dbg_out(T...);
}
template <typename T>
class SafeVector : public vector<T> {
 public:
  using vector<T>::vector;
  typename vector<T>::reference operator[](size_t n) {
    return vector<T>::at(n);
  }
  typename vector<T>::const_reference operator[](size_t n) const {
    return vector<T>::at(n);
  }
};
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MX = 1 << 20;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int c, d;
    cin >> c >> d;
    if ((c - d) % 2 == 1)
      cout << -1 << nl;
    else if (c == d && c == 0)
      cout << 0 << nl;
    else if (c == d)
      cout << 1 << nl;
    else
      cout << 2 << nl;
  }
  return 0;
}
