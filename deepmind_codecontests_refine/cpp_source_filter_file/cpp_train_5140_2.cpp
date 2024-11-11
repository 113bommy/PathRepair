#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
long long n, x, y, c;
long long calcC(long long dis1, long long dis2, long long m) {
  long long hm = max(0LL, m - (dis1 + dis2));
  return (hm * hm + hm) / 2;
}
long long calcB(long long dis, long long m) {
  long long hm = max(0LL, m - dis);
  return hm * hm;
}
bool solve(long long m) {
  long long ar = 0, dis;
  ar += ((m * m) - m) * 2 + 1;
  ar -= calcB(x, m);
  ar -= calcB(n - x + 1, m);
  ar -= calcB(y, m);
  ar -= calcB(n - y + 1, m);
  ar += calcC(x, y, m);
  ar += calcC(n - x + 1, y, m);
  ar += calcC(x, n - y + 1, m);
  ar += calcC(n - x + 1, n - y + 1, m);
  if (ar >= c)
    return true;
  else
    return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> x >> y >> c;
  long long l = 1, r = n * n + 10;
  while (l < r) {
    long long m = (l + r) / 2;
    if (solve(m))
      r = m;
    else
      l = m + 1;
  }
  cout << l - 1 << '\n';
  exit(0);
}
