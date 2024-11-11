#include <bits/stdc++.h>
using namespace std;
char _;
const long long maxN = 1000 * 1000 + 5;
const long long mod = 1000 * 1000 * 1000 + 7;
const long long base = 701;
const long long SQ = 500;
const long long maxL = 20;
vector<long long> a[maxN];
vector<long long> ans[maxN];
vector<long long> v;
vector<pair<long long, long long> > pos[maxN];
long long cntx[maxN], cnty[maxN];
bool cmp(const pair<long long, long long> &p,
         const pair<long long, long long> &q) {
  return (ans[p.first][p.second] > ans[q.first][q.second]);
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) {
      long long x;
      cin >> x;
      v.push_back(x);
      a[i].push_back(x);
      ans[i].push_back(0);
    }
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) {
      long long ps = lower_bound(v.begin(), v.end(), a[i][j]) - v.begin();
      pos[ps].push_back(make_pair(i, j));
    }
  for (long long i = 0; i < v.size(); i++) {
    for (long long j = 0; j < pos[i].size(); j++) {
      long long x = pos[i][j].first, y = pos[i][j].second;
      ans[x][y] = max(cntx[x], cnty[y]) + 1;
    }
    sort(pos[i].begin(), pos[i].end(), cmp);
    for (long long tof = 0; tof < 40; tof++) {
      for (long long j = 0; j < pos[i].size(); j++) {
        long long x = pos[i][j].first, y = pos[i][j].second;
        ans[x][y] = max(ans[x][y], max(cntx[x], cnty[y]));
        cntx[x] = max(cntx[x], ans[x][y]);
        cnty[y] = max(cnty[y], ans[x][y]);
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) cout << ans[i][j] << ' ';
    cout << endl;
  }
  return 0;
}
