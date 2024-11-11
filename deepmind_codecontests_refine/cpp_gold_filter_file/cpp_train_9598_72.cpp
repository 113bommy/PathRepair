#include <bits/stdc++.h>
using namespace std;
const long long inf = 1LL << 60;
long long toInt(string s) {
  long long res;
  stringstream ss;
  ss << s;
  ss >> res;
  return res;
}
string toString(long long n) {
  stringstream ss;
  ss << n;
  return ss.str();
}
template <long long mod>
class modint {
 private:
  long long _num;
  modint set(long long num) {
    _num = num % mod;
    return *this;
  }

 public:
  modint() { _num = 0; }
  modint(long long num) { _num = num % mod; }
  modint operator=(long long x) { return set(x % mod); }
  modint operator+(long long x) { return modint<mod>(_num + (x % mod)); }
  modint operator-(long long x) { return modint<mod>(_num - (x % mod)); }
  modint operator*(long long x) { return modint<mod>(_num * (x % mod)); }
  modint operator+=(long long x) { return set(_num + (x % mod)); }
  modint operator-=(long long x) { return set(_num - (x % mod)); }
  modint operator*=(long long x) { return set(_num * (x % mod)); }
  explicit operator long long() { return _num; }
  friend ostream &operator<<(ostream &os, const modint<mod> &x) {
    os << x._num;
    return os;
  }
};
void run() {
  long long n, a, b, ans = 0;
  cin >> n >> a >> b;
  for (long long i = 0; i < n; i++) {
    if (i >= a && n - i - 1 <= b) {
      ans++;
    }
  }
  cout << ans << endl;
}
int main(int argc, char *argv[]) {
  run();
  return 0;
}
