#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
template <typename T>
T GCD(T a, T b) {
  long long t;
  while (a) {
    t = a;
    a = b % a;
    b = t;
  }
  return b;
}
template <typename T>
string toString(T a) {
  return to_string(a);
}
template <typename T>
void toInt(string s, T &x) {
  stringstream str(s);
  str >> x;
}
inline int add(long long a, long long b) {
  a += b;
  if (a < 0) a += mod;
  return a;
}
inline int sub(long long a, long long b) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}
inline int mul(long long a, long long b) { return (a * 1ll * b) % mod; }
inline int pwr(long long x, long long y) {
  int ans = 1 % mod;
  while (y) {
    if (y & 1) ans = mul(ans, x);
    x = mul(x, x);
    y >>= 1;
  }
  return ans;
}
inline int inv(int a) { return pwr(a, mod - 2); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int a, b;
  vector<pair<int, int> > vec;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    vec.push_back({a, b});
  }
  sort(vec.begin(), vec.end());
  int m;
  cin >> m;
  for (int i = 0; i < n; i++) {
    if (m > vec[i].first) {
      if (m <= vec[i].second) {
        cout << n - i << '\n';
        return 0;
      }
    }
  }
  cout << 0 << '\n';
  return 0;
}
