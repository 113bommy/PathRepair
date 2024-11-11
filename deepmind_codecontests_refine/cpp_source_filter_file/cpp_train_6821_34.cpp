#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long power(unsigned long long a, unsigned long long b,
                unsigned long long ret = 1LL) {
  while (b--) ret = (ret * a);
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  map<int, pair<int, int>> mr, mc;
  for (int i = 1; i <= n; i++) {
    int x, r, a;
    cin >> x >> r >> a;
    if (x == 1)
      mr[r] = {i, a};
    else
      mc[r] = {i, a};
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int f = mr[i].first, x = mr[i].second;
      int s = mc[j].first, y = mc[j].second;
      if (f >= s)
        cout << x << " ";
      else
        cout << y << " ";
    }
    cout << endl;
  }
}
