#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5;
const int mod1 = 954216829;
const int base1 = 307;
const int base2 = 269;
const int mod2 = 1e9 + 9;
long long ans[maxn];
int xx[maxn], yy[maxn];
int n, k, v;
pair<int, int> b[maxn], q[maxn];
pair<int, pair<int, int> > d[3001000];
multiset<pair<int, int> > s;
void add(int cnt, int dist) { ans[cnt] += dist; }
const int T = (1 << 16);
int ord[maxn];
vector<int> st[T + T];
void solve(int mlp) {
  int n = s.size();
  if (n == 0) return;
  int v = n;
  multiset<pair<int, int> >::iterator it = s.begin();
  for (int i = 1; i <= n; i++) {
    b[i] = *it;
    it++;
  }
  int l = 1;
  int cnt = 0;
  while (l <= v) {
    int r = l;
    while (r <= v && b[r].first == b[l].first) r++;
    for (int j = l; j < r; j++) {
      pair<int, int> g = b[j];
      if (g.second == 0)
        cnt--;
      else
        cnt++;
    }
    if (r != v + 1) add(cnt, (b[r].first - b[l].first) * mlp);
    l = r;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  k--;
  for (int i = 1; i <= n; i++) cin >> xx[i] >> yy[i];
  for (int i = 1; i <= n; i++) {
    v++;
    d[v] = make_pair(xx[i] - k, make_pair(1, i));
    v++;
    d[v] = make_pair(xx[i] + 1, make_pair(0, i));
  }
  sort(d + 1, d + v + 1);
  d[v + 1].first = d[v].first + 1;
  int l = 1;
  while (l <= v) {
    int r = l;
    while (r <= v && d[r].first == d[l].first) r++;
    for (int j = l; j < r; j++) {
      pair<int, int> g = d[j].second;
      if (g.first == 0) {
        s.erase(s.find(make_pair(yy[g.second] + 1, 0)));
        s.erase(s.find(make_pair(yy[g.second] - k, 1)));
      } else {
        s.insert(make_pair(yy[g.second] + 1, 0));
        s.insert(make_pair(yy[g.second] - k, 1));
      }
    }
    if (r != v + 1) solve(d[r].first - d[l].first);
    l = r;
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << "\n";
  return 0;
}
