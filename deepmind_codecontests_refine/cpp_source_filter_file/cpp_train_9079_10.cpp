#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct BIT {
  int n;
  vector<T> a;
  BIT(int _n) : n(_n), a(vector<T>(_n + 1)) {}
  void add(int x, int y) {
    x = max(x, 1);
    for (; x <= n; x += x & -x) a[x] += y;
  }
  T query(int x) {
    x = max(min(x, n), 0);
    T ret = 0;
    for (; x; x -= x & -x) ret += a[x];
    return ret;
  }
  T query(int l, int r) {
    if (l > r) return 0;
    return query(r) - query(l - 1);
  }
};
template <typename T>
vector<int> z_function(const T &s, int n) {
  vector<int> z(n);
  for (int i = 1, x = 0, y = 0; i < n; i++) {
    if (i <= y) z[i] = min(y - i, z[i - x]);
    while (i + z[i] < n && s[i + z[i]] == s[z[i]]) ++z[i];
    if (y <= i + z[i]) x = i, y = i + z[i];
  }
  z[0] = n;
  return z;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  string a, b, c;
  cin >> a >> b >> c;
  string t1 = c + "#" + a;
  vector<int> z1 = z_function(t1, t1.size());
  z1.erase(z1.begin(), z1.begin() + m + 1);
  string t2 = b + "#" + c;
  reverse((t2).begin(), (t2).end());
  vector<int> z2 = z_function(t2, t2.size());
  z2.erase(z2.begin(), z2.begin() + m + 1);
  reverse((z2).begin(), (z2).end());
  for (auto &e : z1) e = min(e, m - 1);
  for (auto &e : z2) e = min(e, m - 1);
  BIT<int> bit1(n);
  BIT<long long> bit2(n);
  long long ans = 0;
  for (int i = 0, j = 0; i < n; i++) {
    while (j < n && j < i + m - 1) {
      bit1.add(z2[j], 1);
      bit2.add(z2[j], z2[j]);
      j++;
    }
    int x = m - z1[i] - 1;
    ans += bit2.query(x, m) + (long long)(z1[i] - m + 1) * bit1.query(x, m);
    bit1.add(z2[i], -1);
    bit2.add(z2[i], -z2[i]);
  }
  cout << ans << '\n';
  return 0;
}
