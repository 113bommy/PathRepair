#include <bits/stdc++.h>
using namespace std;
long long n;
map<long long, map<long long, long long[3]>> mp;
map<long long, map<long long, bool[3]>> mpb;
int go(long long a, long long b, bool g = 1) {
  if (mpb[a][b][g]) return mp[a][b][g];
  mpb[a][b][g] = true;
  long long r = 1;
  if (b > 32) {
    return mp[a][b][g] = 2;
  }
  if (b == 1 && a > 100000) {
    if ((n - a) % 2) return mp[a][b][g] = 1;
    return mp[a][b][g] = 0;
  }
  for (int i = b; i >= 1; i--) {
    r *= a;
    if (r >= n) break;
  }
  if (r >= n) return mp[a][b][g] = g;
  if (g) {
    long long x2 = go(a, b + 1, 0);
    long long x1 = go(a + 1, b, 0);
    if (x1 == 1 || x2 == 1)
      return mp[a][b][g] = 1;
    else if (x1 == 2 || x2 == 2)
      return mp[a][b][g] = 2;
    else
      return mp[a][b][g] = 0;
  } else {
    long long x2 = go(a, b + 1, 1);
    long long x1 = go(a + 1, b, 1);
    if (x1 == 0 || x2 == 0)
      return mp[a][b][g] = 0;
    else if (x1 == 2 || x2 == 2)
      return mp[a][b][g] = 2;
    else
      return mp[a][b][g] = 1;
  }
}
int main() {
  long long a, b;
  cin >> a >> b >> n;
  cout << (go(a, b) == 2 ? "Missing" : (go(a, b) == 1 ? "Masha" : "Stas"));
  return 0;
}
