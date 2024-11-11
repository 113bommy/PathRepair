#include <bits/stdc++.h>
using namespace std;
const int INF = 0x6fffffff;
const int MINF = 0x80000000;
const long long mod = 1000000007;
const int cons = 100001;
const double pi = 3.141592653589793;
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  int x, s;
  cin >> x >> s;
  vector<pair<int, int> > dat(m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &dat[i].first);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &dat[i].second);
  }
  dat.push_back(make_pair(x, 0));
  sort(dat.begin(), dat.end());
  int last = 0x7fffffff;
  for (int i = 0; i < dat.size(); i++) {
    if (dat[i].second < last) {
      last = dat[i].second;
    } else {
      dat[i].first = 0x7fffffff;
      dat[i].second = 0x7fffffff;
    }
  }
  sort(dat.begin(), dat.end());
  while (dat.size() && dat.back().first == 0x7fffffff) dat.pop_back();
  vector<int> kdat(k);
  map<int, int> km;
  for (int i = 0; i < k; i++) {
    scanf("%d", &kdat[i]);
  }
  for (int i = 0; i < k; i++) {
    int x;
    scanf("%d", &x);
    int t = km[x];
    km[x] = max(t, kdat[i]);
  }
  km[0] = 0;
  long long ans = (long long)x * n;
  for (int i = 0; i < dat.size(); i++) {
    int rem = s - dat[i].second;
    if (rem < 0) continue;
    auto it = km.upper_bound(rem);
    if (it == km.begin()) continue;
    it--;
    ans = min(ans,
              max(0LL, ((long long)n - it->second) * (long long)dat[i].first));
  }
  printf("%lld\n", ans);
  return 0;
}
