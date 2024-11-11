#include <bits/stdc++.h>
using namespace std;
long n, m, p, a, b, c;
long long d[100117], arr[100117], ps[100117], dp[117][100117];
vector<pair<long long, long long> > q;
bool conv(pair<long long, long long> l1, pair<long long, long long> l2,
          pair<long long, long long> l3) {
  return (l2.first - l1.first) * (l1.second - l3.second) <=
         (l1.second - l2.second) * (l3.first - l1.first);
}
void add(long long k, long long b) {
  pair<long long, long long> x = make_pair(k, b);
  while (q.size() > 1 && conv(q[q.size() - 2], q[q.size() - 1], x))
    q.pop_back();
  q.push_back(x);
}
long long get(long long x) {
  if (c >= q.size()) c = q.size() - 1;
  while (c < q.size() - 1 && (q[c].first * x + q[c].second) >=
                                 (q[c + 1].first * x + q[c + 1].second))
    c++;
  return (q[c].first * x + q[c].second);
}
int main() {
  scanf("%ld %ld", &n, &m);
  scanf("%ld", &p);
  ;
  d[0] = 0;
  for (long i = 0; i < n - 1; ++i) {
    scanf("%I64d", &d[i + 1]);
    d[i + 1] += d[i];
  }
  for (long i = 0; i < m; ++i) {
    scanf("%ld %ld", &a, &b);
    arr[i] = b - d[a - 1];
  }
  sort(arr, arr + m);
  ps[0] = 0;
  for (long i = 0; i < m; ++i) ps[i + 1] = arr[i] + ps[i];
  for (long i = 0; i < p; ++i) dp[i][0] = 0;
  for (long j = 1; j < m + 1; ++j)
    dp[0][j] = dp[0][j - 1] + (j - 1) * (arr[j - 1] - arr[j - 2]);
  for (long i = 1; i < p; ++i) {
    q.clear();
    add(0, 0);
    c = 0;
    for (long j = 1; j < m + 1; ++j) {
      dp[i][j] = j * arr[j - 1] - ps[j] + get(arr[j - 1]);
      add(-j, dp[i - 1][j] + ps[j]);
    }
  }
  printf("%I64d", dp[p - 1][m]);
  return 0;
}
