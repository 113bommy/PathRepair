#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1e18;
const int N = 2e6 + 5;
const long long MOD = 998244353;
int parent[N];
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
long long pow(long long x, long long y, long long p) {
  if (y == 0) return 1;
  long long res = 1;
  x %= p;
  if (x == 0) return 0LL;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y >>= 1;
    x = (x * x) % p;
  }
  return res;
}
int find(int x) { return x == parent[x] ? x : parent[x] = find(parent[x]); }
void Union(int x, int y) {
  int xPar = find(x), yPar = find(y);
  if (xPar != yPar) parent[xPar] = yPar;
}
void solve() {
  int n, x;
  cin >> n >> x;
  int flag = (n % 2 == 0);
  n %= 3;
  while (n > 0) {
    if (flag) {
      if (x == 2)
        x = 1;
      else if (x == 1)
        x = 2;
      flag = 0;
    } else {
      if (x == 0)
        x = 1;
      else if (x == 1)
        x = 0;
      flag = 1;
    }
    n--;
  }
  cout << x << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
