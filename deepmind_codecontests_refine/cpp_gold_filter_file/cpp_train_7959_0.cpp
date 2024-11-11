#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long t = -1e18, t1 = -1e18, t2 = -1e18, t3 = -1e18;
int main() {
  cin >> n >> m;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    long long x, y;
    cin >> x >> y;
    t = max(x + y, t);
    t1 = max(x - y, t1);
    t2 = max(-x + y, t2);
    t3 = max(-x - y, t3);
  }
  cin >> m;
  pair<long long, long long> res;
  res.first = 1e14;
  for (int i = 0; i < m; ++i) {
    long long x, y;
    cin >> x >> y;
    long long p = -x - y + t;
    p = max(p, -x + y + t1);
    p = max(p, x - y + t2);
    p = max(p, x + y + t3);
    if (p < res.first) {
      res.first = p;
      res.second = i;
    }
  }
  cout << res.first << endl;
  cout << res.second + 1;
}
