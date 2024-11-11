#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long MAX = 2e5 + 5;
const long long MOD = 1e9 + 7;
long long n, m, k, x, s, si;
pair<long long, long long> ab[MAX];
vector<pair<long long, long long> > v;
long long c[MAX];
long long d[MAX];
void build() {
  sort(ab, ab + m);
  long long mb = ab[0].second;
  v.push_back(ab[0]);
  for (int i = 1; i < m; i++) {
    if (ab[i].second < mb) {
      mb = ab[i].second;
      v.push_back(ab[i]);
    }
  }
  si = ((long long)(v).size());
  ;
}
long long ans(long long p, long long mam) {
  if (mam < 0) return INF;
  if (p < 0) return 0;
  pair<long long, long long> nn = {mam, INF};
  int xx = upper_bound(v.begin(), v.end(), nn) - v.begin();
  if (xx == 0) return INF;
  return p * v[xx - 1].second;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  cin >> x >> s;
  for (int i = 0; i < m; i++) cin >> ab[i].second;
  for (int i = 0; i < m; i++) cin >> ab[i].first;
  ab[m].second = x;
  ab[m].first = 0;
  m++;
  for (int i = 0; i < k; i++) cin >> c[i];
  for (int i = 0; i < k; i++) cin >> d[i];
  build();
  long long mi = ans(n, s);
  for (int i = 0; i < k; i++) {
    mi = min(mi, ans(n - c[i], s - d[i]));
  }
  cout << mi << '\n';
}
