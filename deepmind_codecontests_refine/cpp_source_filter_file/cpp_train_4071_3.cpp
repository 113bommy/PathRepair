#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e16;
const double EPS = 1e-6;
const long long MOD = (long long)(2e9 + 99);
const long long MAXV = (long long)(4e5 + 10);
const long long MAXE = (long long)(2e5 + 10);
const long long MAXLOG = (long long)(20);
long long n, m;
long long parties[3005][3005];
long long cnt[3005];
long long sum[3005][3005];
vector<pair<long long, pair<long long, long long> > > C;
long long mark[3005];
long long calc(long long v) {
  int k = max(v - cnt[1], 0LL);
  long long sol = 0;
  for (int i = 2; i <= m; i++) {
    long long sobran = max(cnt[i] - v + 1, 0LL);
    if (sobran > k) return INF;
    if (sobran) {
      k -= sobran;
      sol += sum[i][sobran - 1];
    }
    mark[i] = sobran;
  }
  for (int i = 0; i < n; i++) {
    if (k <= 0) break;
    int P = C[i].second.first;
    int idx = C[i].second.second;
    if (idx >= mark[P]) {
      sol += C[i].first;
      k--;
    }
  }
  return sol;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    long long p, c;
    cin >> p >> c;
    parties[p][cnt[p]++] = c;
  }
  for (int i = 1; i <= m; i++) sort(parties[i], parties[i] + cnt[i]);
  for (int i = 1; i <= m; i++)
    for (int j = 0; j < cnt[i]; j++) {
      sum[i][j] = parties[i][j];
      if (j) sum[i][j] += sum[i][j - 1];
      C.push_back(pair<long long, pair<long long, long long> >(
          parties[i][j], pair<long long, long long>(i, j)));
    }
  sort(C.begin(), C.end());
  long long sol = INF;
  for (long long v = 0; v <= n; v++) {
    sol = min(sol, calc(v));
  }
  cout << sol << "\n";
  return 0;
}
