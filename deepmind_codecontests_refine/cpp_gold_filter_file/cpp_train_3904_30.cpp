#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long modI(long long a, long long m);
long long gcd(long long a, long long b);
long long powM(long long x, long long y, long long m);
void py(int ok) {
  if (ok == 1) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
}
void swap(long long& a, long long& b) {
  long long tp = a;
  a = b;
  b = tp;
}
long long gcd(long long x, long long y) {
  if (x == 0) return y;
  return gcd(y % x, x);
}
long long lcm(long long x, long long y) {
  if (x == 0 || y == 0) {
    cout << "Not valid lcm"
         << "\n";
  }
  long long LCM = x / gcd(x, y);
  LCM = LCM * y;
  return LCM;
}
long long powM(long long x, long long y, long long m) {
  long long ans = 1, r = 1;
  x %= m;
  while (r > 0 && r <= y) {
    if (r & y) {
      ans *= x;
      ans %= m;
    }
    r <<= 1;
    x *= x;
    x %= m;
  }
  return ans;
}
long long modI(long long a, long long m) {
  long long m0 = m, y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m;
    a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  int tt = 1;
  for (int testcase_no = 1; testcase_no <= tt; testcase_no++) {
    int n, m, k;
    cin >> n >> m >> k;
    int x[k], y[k];
    int ok = 0;
    for (int i = 0; i < k; i++) {
      cin >> x[i] >> y[i];
      if (min(x[i], n - x[i] + 1) <= 5 || min(y[i], m - y[i] + 1) <= 5) ok = 1;
    }
    py(ok);
  }
  return 0;
}
