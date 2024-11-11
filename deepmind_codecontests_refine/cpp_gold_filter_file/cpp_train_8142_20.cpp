#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007LL;
const long long p = 182731LL;
long long st(long long y) {
  if (y == 0) return 1;
  if (y % 2 == 0) {
    long long k = st(y / 2);
    return (k * k) % mod;
  } else {
    return (st(y - 1) * p) % mod;
  }
}
bool f(long long a1, long long y1, long long b1, long long a2, long long y2,
       long long b2) {
  long long a = ((a1 - b1) + mod) % mod;
  a *= st(mod - 1 - y1);
  a %= mod;
  long long b = ((a2 - b2) + mod) % mod;
  b *= st(mod - 1 - y2);
  b %= mod;
  if (a != b && mod - a != b) {
    return false;
  }
  return true;
}
vector<long long> x;
vector<int> y;
bool srv(int a1, int a2, int b) {
  if (y[a1 + b - 1] - y[a1 - 1] == y[a2 + b - 1] - y[a2 - 1] &&
      f(x[a1 + b - 1], y[a1 - 1], x[a1 - 1], x[a2 + b - 1], y[a2 - 1],
        x[a2 - 1])) {
    return 1;
  } else {
    return 0;
  }
}
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  x.resize(n + 1, 0);
  y.resize(n + 1, 0);
  y[0] = 0;
  for (int i = 1; i <= n; i++) {
    y[i] = y[i - 1] + 1 - s[i - 1] + '0';
  }
  {
    long long h = 1;
    long long k = 1;
    for (int i = 1; i <= n; i++) {
      if (s[i - 1] == '0') {
        h++;
      } else {
        x[i] = (k * st(h) % mod + mod) % mod;
        k *= -1;
      }
      x[i] += x[i - 1];
      x[i] %= mod;
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int a1, a2;
    int b;
    cin >> a1 >> a2 >> b;
    if (srv(a1, a2, b)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  cin >> n;
  return 0;
}
