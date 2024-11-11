#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5, mod = 1e9 + 7, INF = 0x3f3f3f3f;
int n, m;
long long qpow(long long a, long long b) {
  long long c = 1;
  while (b) {
    if (b & 1) c = (c * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return c % mod;
}
long long inv(long long x) { return qpow(x, mod - 2); }
long long b[N], a[N];
struct hh {
  int a, b, c;
};
vector<hh> g;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int _ = 1;
  cin >> _;
  for (int i = 1; i <= _; i++) {
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    if (sum % n == 0) {
      sum /= n;
      priority_queue<pair<int, int>, vector<pair<int, int>>,
                     greater<pair<int, int>>>
          pq;
      for (int i = 2; i <= n; i++) {
        pq.push({i - a[i] % i, i});
      }
      bool f = 1;
      while (pq.size()) {
        auto t = pq.top();
        pq.pop();
        int k = t.second, x = t.first;
        a[k] += x, a[1] -= x;
        if (a[1] < 0) {
          f = 0;
          break;
        }
        g.push_back({1, k, x});
        x = a[k] / k;
        a[1] += x * k, a[k] = 0;
        g.push_back({k, 1, x});
      }
      for (int i = n; i >= 2; i--) {
        if (a[i] == sum) continue;
        g.push_back({1, i, int(sum)});
      }
      if (!f)
        cout << -1 << endl;
      else {
        cout << g.size() << endl;
        for (int i = 0; i < g.size(); i++)
          cout << g[i].a << " " << g[i].b << " " << g[i].c << endl;
      }
      g.clear();
    } else
      cout << -1 << endl;
  }
}
