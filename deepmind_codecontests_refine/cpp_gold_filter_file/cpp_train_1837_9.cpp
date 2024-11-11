#include <bits/stdc++.h>
using namespace std;
long long n, m, r, k;
long long nets(long long x, long long y) {
  long long h = r, w = r;
  if (x + r > n) h -= x + r - n;
  if (r - 1 > x) h -= r - x - 1;
  if (y + r > m) w -= y + r - m;
  if (r - 1 > y) w -= r - 1 - y;
  return h * w;
}
map<long long, int> used;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> r >> k;
  long double s = 0, t = (n - r + 1) * (m - r + 1);
  long long x = n / 2, y = m / 2;
  priority_queue<pair<long long, long long>> q;
  q.push({nets(x, y), x * m + y});
  used[x * m + y] = 1;
  while (k) {
    k--;
    auto p = q.top();
    q.pop();
    s += p.first;
    x = p.second / m;
    y = p.second % m;
    if (x && !used.count(x * m + y - m)) {
      q.push({nets(x - 1, y), x * m + y - m});
      used[x * m + y - m] = 1;
    }
    if (x + 1 < n && !used.count(x * m + y + m)) {
      q.push({nets(x + 1, y), x * m + y + m});
      used[x * m + y + m] = 1;
    }
    if (y && !used.count(x * m + y - 1)) {
      q.push({nets(x, y - 1), x * m + y - 1});
      used[x * m + y - 1] = 1;
    }
    if (y + 1 < m && !used.count(x * m + y + 1)) {
      q.push({nets(x, y + 1), x * m + y + 1});
      used[x * m + y + 1] = 1;
    }
  }
  cout << fixed << setprecision(25) << s / t;
  return 0;
}
