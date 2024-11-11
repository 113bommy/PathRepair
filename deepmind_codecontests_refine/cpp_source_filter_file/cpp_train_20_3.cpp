#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, x[N], v[N];
vector<pair<int, int>> p;
long long bit1[N], bit2[N], ans;
void add(int p, int v, long long *bit) {
  for (p += 2; p < N; p += p & -p) bit[p] += v;
}
long long query(int p, long long *bit) {
  long long r = 0;
  for (p += 2; p; p -= p & -p) r += bit[p];
  return r;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> x[i];
  for (int i = 1; i <= n; i++) cin >> v[i];
  for (int i = 1; i <= n; i++) p.push_back({x[i], v[i]});
  sort(p.begin(), p.end());
  sort(v, v + n);
  for (auto &x : p) {
    x.second = lower_bound(v, v + n, x.second) - v + 1;
    ans += 1ll * x.first * query(x.second, bit1) - query(x.second, bit2);
    add(x.second, 1, bit1);
    add(x.second, x.first, bit2);
  }
  cout << ans << "\n";
}
