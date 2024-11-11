#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline int popcount(T t) {
  if (std::numeric_limits<T>::digits <=
      std::numeric_limits<unsigned int>::digits) {
    return __builtin_popcount(t);
  } else {
    return __builtin_popcountll(t);
  }
}
const long double EPS = 1e-8;
const long double PI = acosl(0.0) * 2;
void solve() {
  int n;
  cin >> n;
  long long k, p;
  cin >> k >> p;
  vector<vector<int> > g(n);
  for (int i = 0; i < int(n - 1); ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  queue<int> q;
  q.push(0);
  vector<int> d(n, -1);
  d[0] = 0;
  vector<long long> cnt(n);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    ++cnt[d[v]];
    for (int i = 0; i < int((g[v]).size()); ++i) {
      int u = g[v][i];
      if (d[u] == -1) {
        d[u] = d[v] + 1;
        q.push(u);
      }
    }
  }
  long long ans = 0;
  int l = n - 1;
  vector<long long> sum((cnt).begin(), (cnt).end());
  for (int i = 1; i <= int(n - 1); ++i) sum[i] += sum[i - 1];
  while (l > 0 && cnt[l] == 0) --l;
  int r = l;
  while (l > 0 && r > 0) {
    while (r > 0 && cnt[r] <= k && (l - r) * cnt[r] <= p) {
      k -= cnt[r];
      p -= (l - r) * cnt[r];
      --r;
    }
    long long cand = sum[l] - sum[r];
    long long add = k;
    if (r != l) add = min(k, p / (l - r));
    if (r == 0) add = 0;
    ans = max(ans, add + cand);
    if (r != l) k += cnt[l];
    if (r < l) {
      p += sum[l + 1] - sum[r];
    }
    --l;
    r = min(r, l);
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
