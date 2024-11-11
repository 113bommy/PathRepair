#include <bits/stdc++.h>
using namespace std;
constexpr const int maxn = 1 << 17;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> x;
  while (m--) {
    int _x;
    cin >> _x;
    if (x.empty() || x.back() != _x) x.push_back(_x);
  }
  m = x.size();
  long long res = 0;
  vector<long long> in(n + 1), out(n + 1);
  for (int i = 1; i != m; ++i) {
    int a = x[i], b = x[i - 1];
    if (a < b) swap(a, b);
    res += a - b;
    in[b] += b - 1;
    out[b] -= b;
    in[a] += b + b - a + 1;
    out[a] -= b + b - a;
  }
  for (int i = 1; i <= n; ++i) {
    res += in[i];
    cout << res << " \n"[i == n];
    res += out[i];
  }
}
