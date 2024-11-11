#include <bits/stdc++.h>
using namespace std;
const uint64_t seed =
    std::chrono::system_clock::now().time_since_epoch().count();
mt19937_64 rnd(seed);
const int MOD = 998244353;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  unordered_map<long long, vector<int>> mm;
  mm[0].push_back(0);
  vector<long long> pp(n + 1);
  for (int i = 0; i <= n; i++) {
    pp[i] = rnd();
  }
  vector<int> cnt(n, 0);
  long long key = 0;
  for (int i = 0; i < n; i++) {
    int last = cnt[a[i]];
    cnt[a[i]] = (cnt[a[i]] + 1) % 3;
    int nc = cnt[a[i]];
    key = key + (nc - last) * pp[a[i]];
    mm[key].push_back(i + 1);
  }
  vector<int> nn(n + 1, n);
  int p = 0;
  vector<int> cnt1(n, 0);
  vector<int> cnt2(n, 0);
  for (int i = 0; i < n; i++) {
    while (p < n && cnt2[a[p]] + 1 - cnt1[a[p]] <= 3) {
      cnt2[a[p]]++;
      p++;
    }
    nn[i] = p;
    cnt1[a[i]]++;
  }
  long long ans = 0;
  for (auto p : mm) {
    auto &v = p.second;
    int q = 0;
    for (int i = 0; i < v.size(); i++) {
      while (q < v.size() && v[q] <= nn[v[i]]) q++;
      ans += q - i - 1;
    }
  }
  cout << ans << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(10);
  int T = 1;
  for (int i = 1; i <= T; i++) {
    solve();
  }
  cout.flush();
  return 0;
}
