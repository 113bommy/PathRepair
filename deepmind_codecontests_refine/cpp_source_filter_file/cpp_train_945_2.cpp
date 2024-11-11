#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
inline long long rint() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
long long gcd(long long a, long long b) { return (b) ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long pow(long long a, long long b, long long q) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % q;
    a = a * a % q;
    b >>= 1;
  }
  return ans;
}
const long long mod = 998244353;
const long long N = 2e6 + 5;
int main() {
  int n = rint();
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) a[i] = rint(), b[i] = rint();
  vector<int> fac;
  for (int i = 2; i * i <= a[0]; i++) {
    if (a[0] % i == 0) {
      fac.push_back(i);
      while (a[0] % i == 0) a[0] /= i;
    }
  }
  if (b[0] != 1) fac.push_back(b[0]);
  for (int i = 2; i * i <= b[0]; i++) {
    if (b[0] % i == 0) {
      fac.push_back(i);
      while (b[0] % i == 0) b[0] /= i;
    }
  }
  if (b[0] != 1) fac.push_back(b[0]);
  sort((fac).begin(), (fac).end());
  fac.erase(unique((fac).begin(), (fac).end()), fac.end());
  for (int i = 1; i < n; i++) {
    int jb = 0;
    while (jb != fac.size()) {
      if (a[i] % fac[jb] == 0 || b[i] % fac[jb] == 0)
        jb++;
      else
        fac.erase(fac.begin() + jb);
    }
  }
  if (fac.size() == 0)
    cout << -1 << "\n";
  else
    cout << fac[0] << "\n";
}
