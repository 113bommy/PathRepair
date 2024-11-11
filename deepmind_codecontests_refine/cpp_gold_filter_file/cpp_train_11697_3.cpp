#include <bits/stdc++.h>
using namespace std;
mt19937 gen(time(0));
bool IS_ONE_TEST = 1;
void update(int idx, int d, vector<int> &f) {
  for (; idx < f.size(); idx += (idx & (-idx))) f[idx] += d;
}
int sum(int idx, vector<int> &f) {
  int res = 0;
  for (; idx > 0; idx -= (idx & (-idx))) res += f[idx];
  return res;
}
int sum(int l, int r, vector<int> &f) { return sum(r, f) - sum(l - 1, f); }
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  set<long long> s;
  map<long long, long long> to;
  int num = 1;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    s.insert(a[i]);
  }
  for (auto &elem : s) to[elem] = num++;
  for (int i = 0; i < n; ++i) a[i] = to[a[i]];
  vector<int> fenw_r(n + 10), fenw_l(n + 10);
  long long total = 0;
  int r = 1;
  for (int i = 1; i < n; ++i) {
    total += sum(a[i] + 1, n + 5, fenw_r);
    update(a[i], 1, fenw_r);
  }
  long long ans = 0;
  for (int l = 0; l + 1 < n; ++l) {
    total += sum(a[l] + 1, n + 5, fenw_l);
    total += sum(a[l] - 1, fenw_r);
    update(a[l], 1, fenw_l);
    while (r < n && (total > k || l >= r)) {
      total -= sum(a[r] + 1, n + 5, fenw_l);
      total -= sum(a[r] - 1, fenw_r);
      update(a[r], -1, fenw_r);
      ++r;
    }
    if (total <= k) ans += n - r;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(15);
  int t;
  if (IS_ONE_TEST)
    t = 1;
  else
    cin >> t;
  while (t-- > 0) {
    solve();
  }
}
