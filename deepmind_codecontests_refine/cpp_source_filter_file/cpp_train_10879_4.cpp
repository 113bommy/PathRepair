#include <bits/stdc++.h>
using namespace std;
const unsigned long long M = 1000000007;
unsigned long long n, l, k, a[1000005], ans;
vector<vector<unsigned long long> > pd;
pair<unsigned long long, unsigned long long> p[1000005];
map<unsigned long long, unsigned long long> m;
unordered_map<unsigned long long, unsigned long long> nrm;
void add(unsigned long long x) { ans = (ans + x) % M; }
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> l >> k;
  for (unsigned long long i = 0; i < n; ++i) {
    cin >> a[i];
    ++m[a[i]];
  }
  k = min(k, (l - 1) / n + 1);
  if (k == 1) {
    cout << l % M;
    return 0;
  }
  unsigned long long cnt = -1;
  for (map<unsigned long long, unsigned long long>::iterator it = m.begin();
       it != m.end(); ++it) {
    p[++cnt] = *it;
    nrm[it->first] = cnt;
  }
  vector<unsigned long long> gol;
  gol.resize(cnt + 2, 0);
  for (unsigned long long i = 0; i <= k + 2; ++i) pd.push_back(gol);
  unsigned long long now = 0;
  for (unsigned long long i = 0; i <= cnt; ++i) {
    now += p[i].second;
    now %= M;
    pd[1][i] = now;
  }
  ans = l % M;
  for (unsigned long long i = 2; i <= k; ++i) {
    pd[i][0] = (pd[i - 1][0] * p[0].second) % M;
    for (unsigned long long j = 1; j <= cnt; ++j)
      pd[i][j] = (pd[i][j - 1] + pd[i - 1][j] * p[j].second) % M;
    add(pd[i][cnt] * ((l - 1) / n - (i - 1)));
  }
  unsigned long long last = l % n;
  if (last == 0) last = n;
  for (unsigned long long t = k; t >= 2; --t)
    for (unsigned long long i = 0; i < last; ++i) add(pd[t - 1][nrm[a[i]]]);
  cout << ans;
  return 0;
}
