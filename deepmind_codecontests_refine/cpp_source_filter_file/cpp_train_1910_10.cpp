#include <bits/stdc++.h>
using namespace std;
bool enLinea(pair<long long, long long> a, pair<long long, long long> b,
             pair<long long, long long> c) {
  long long dx1 = a.first - b.first;
  long long dy1 = a.second - b.second;
  long long dx2 = a.first - c.first;
  long long dy2 = a.second - c.second;
  return dx1 * dy2 == dx2 * dy1;
}
long long mcd(long long a, long long b) {
  if (b == 0) return a;
  return mcd(b, a % b);
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<long long, long long> > f(m);
  for (int i = 0; i < m; i++) cin >> f[i].first >> f[i].second;
  vector<int> bin(n, 1);
  for (int i = 0; i < m; i++)
    for (int j = i + 1; j < m; j++) {
      pair<long long, long long> a = f[i];
      pair<long long, long long> b = f[j];
      long long dx = a.first - b.first;
      long long dy = a.second - b.second;
      if (dy == 0) continue;
      if (dy < 0) {
        dx = -dx;
        dy = -dy;
      }
      if ((a.second * dx) % dy != 0) continue;
      long long first = a.first - a.second / dy * dx;
      if (first < 1 || first > n) continue;
      first--;
      int ct = 0;
      for (int k = 0; k < m; k++)
        if (enLinea(a, b, f[k])) ct++;
      bin[first] = max(bin[first], ct);
    }
  int r = 0;
  for (int i = 0; i < n; i++) r += bin[i];
  cout << r << endl;
}
