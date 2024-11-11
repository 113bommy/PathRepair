#include <bits/stdc++.h>
long long gcd(long long m, long long n) { return n == 0 ? m : gcd(n, m % n); }
long long lcm(long long m, long long n) { return m * n / gcd(m, n); }
long long pows(long long base, long long power, long long mod) {
  long long result = 1;
  while (power > 0) {
    if (power & 1) {
      result = result * base % mod;
    }
    power >>= 1;
    base = (base * base) % mod;
  }
  return result;
}
long long poww(long long base, long long power) {
  long long result = 1;
  while (power > 0) {
    if (power & 1) {
      result = result * base;
    }
    power >>= 1;
    base = (base * base);
  }
  return result;
}
const long long inf = 1e17;
const int N = 3e5 + 10 + 10000;
const int M = 1e5 + 10;
const long long mod = 1e9 + 7;
using namespace std;
long long x, y;
vector<long long> ls, rs;
long long vis[N];
int main() {
  scanf("%lld %lld", &x, &y);
  long long pd = 1;
  while (pd * (pd + 1) / 2 <= x + y) {
    pd++;
  }
  for (long long i = pd; i >= 1; i--) {
    if (!vis[i] && x >= i) {
      vis[i] = 1;
      ls.push_back(i);
      x -= i;
    }
  }
  for (long long i = pd; i >= 1; i--) {
    if (!vis[i] && y >= i) {
      vis[i] = 1;
      rs.push_back(i);
      y -= i;
    }
  }
  cout << ls.size() << endl;
  for (auto xs : ls) cout << xs << " ";
  cout << endl;
  cout << rs.size() << endl;
  for (auto xs : rs) cout << xs << " ";
  cout << endl;
  return 0;
}
