#include <bits/stdc++.h>
using namespace std;
using namespace rel_ops;
using ll = int64_t;
using Pii = pair<int, int>;
using ull = uint64_t;
using Vi = vector<int>;
void run();
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(10);
  run();
  return 0;
}
int uplg(int n) { return 32 - __builtin_clz(n); }
int uplg(ll n) { return 64 - __builtin_clzll(n); }
constexpr int MAX_N = 200000;
constexpr int MAX_VAL = 5000000;
constexpr int MAX_FACTORS = 8;
int dp[MAX_VAL][MAX_FACTORS];
int prefs[MAX_FACTORS * 2];
Vi factor(MAX_VAL + 1);
void sieve() {
  for (int i = 2; i * i <= MAX_VAL; i++)
    if (!factor[i])
      for (int j = i * i; j <= MAX_VAL; j += i)
        if (!factor[j]) factor[j] = i;
  for (int i = (0); i < (MAX_VAL + 1); i++)
    if (!factor[i]) factor[i] = i;
}
Vi factorize(ll n) {
  Vi ret;
  while (n > 1) {
    int f = factor[n];
    if (ret.empty() || ret.back() != f)
      ret.push_back(f);
    else
      ret.pop_back();
    n /= f;
  }
  return ret;
}
void run() {
  int n, m;
  cin >> n >> m;
  Vi elems(n);
  for (auto& e : (elems)) cin >> e;
  vector<Pii> queries(m);
  for (auto& q : (queries)) {
    cin >> q.first >> q.second;
    q.first--;
  }
  Vi answers(m, -1);
  Vi sorted(m);
  iota((sorted).begin(), (sorted).end(), 0);
  sort((sorted).begin(), (sorted).end(),
       [&](int l, int r) { return queries[l].first > queries[r].first; });
  for (int i = (0); i < (MAX_N); i++)
    for (int j = (0); j < (MAX_FACTORS); j++) dp[i][j] = 1e9;
  for (int j = (0); j < (MAX_FACTORS * 2); j++) prefs[j] = 1e9;
  int cur = 0;
  sieve();
  for (int begin = n - 1; begin >= 0; begin--) {
    Vi factors = factorize(elems[begin]);
    for (int i = (0); i < (1 << int((factors).size())); i++) {
      int div = 1;
      int inter = __builtin_popcount(i);
      for (int j = (0); j < (int((factors).size())); j++)
        if ((i >> j) & 1) div *= factors[j];
      for (int count = (0); count < (MAX_FACTORS); count++) {
        int pos = dp[div][count];
        int val = int((factors).size()) + count - 2 * inter;
        prefs[val] = min(prefs[val], pos);
      }
      dp[div][int((factors).size())] = begin;
    }
    while (cur < m && queries[sorted[cur]].first == begin) {
      for (int i = (0); i < (MAX_FACTORS * 2); i++) {
        if (prefs[i] < queries[sorted[cur]].second) {
          answers[sorted[cur]] = i;
          break;
        }
      }
      cur++;
    }
  }
  for (auto& a : (answers)) cout << a << '\n';
}
