#include <bits/stdc++.h>
using namespace std;
deque<pair<long long, long long>> batch;
void insert_dreapta(long long n, long long m);
long long eval(long long x);
long double intersect(pair<long long, long long> a,
                      pair<long long, long long> b);
long long a[100010], b[100010];
long long dp[100010];
int main() {
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  for (long long i(0); i < n; i++) cin >> a[i];
  for (long long i(0); i < n; i++) cin >> b[i];
  insert_dreapta(b[0], dp[0]);
  for (long long i(1); i < n; i++) {
    dp[i] = eval(a[i]);
    insert_dreapta(b[i], dp[i]);
  }
  cout << dp[n - 1];
  return 0;
}
void insert_dreapta(long long n, long long m) {
  long long s(batch.size());
  while (batch.size() >= 2 && intersect(batch[s - 1], batch[s - 2]) >=
                                  intersect(batch[s - 1], {n, m})) {
    batch.pop_back();
    s--;
  }
  batch.push_back({n, m});
}
long long eval(long long x) {
  while (batch.size() > 1 && batch[1].first * x + batch[1].second <
                                 batch[0].first * x + batch[0].second)
    batch.pop_front();
  return batch[0].first * x + batch[0].second;
}
long double intersect(pair<long long, long long> a,
                      pair<long long, long long> b) {
  return 1ll * (a.second - b.second) / (b.first - a.first);
}
