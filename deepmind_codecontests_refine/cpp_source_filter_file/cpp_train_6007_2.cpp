#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long double PI = 3.141592653589793116;
const long long INF = 1e18;
const long long _INF = -1e18;
int getbit(int x, int i) { return (x >> i) & 1; }
int onbit(int x, int i) { return (x | (1 << i)); }
int offbit(int x, int i) { return (1 & ~(x >> i)); }
long long p, q, b;
int gcd(long long a, long long b) {
  while (b != 0) {
    long long r = a % b;
    a = b;
    b = r;
  }
  return a;
}
void Input() { cin >> p >> q >> b; }
void Solve() {
  long long t = gcd(p, q);
  q /= t;
  b = gcd(q, b);
  while (b != 1) {
    while (q % b == 0) q /= b;
    b = gcd(q, b);
  }
  if (q == 1)
    cout << "Finite" << '\n';
  else
    cout << "Infinite" << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    Input();
    Solve();
  }
  return 0;
}
