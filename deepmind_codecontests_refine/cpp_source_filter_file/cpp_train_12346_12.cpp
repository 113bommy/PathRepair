#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000;
long long n, c, d, maxy = -1, md = -1, mc = -1, maxc[maxn], maxd[maxn], l;
vector<pair<long long, long long> > vc, vd;
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.second == b.second)
    return a.first > b.first;
  else
    return a.second < b.second;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> c >> d;
  for (int i = 0; i < n; i++) {
    long long b, p;
    char s;
    cin >> b >> p >> s;
    if (s == 'C')
      vc.push_back(make_pair(b, p));
    else
      vd.push_back(make_pair(b, p));
    if (vd.size() != 0 && vd[vd.size() - 1].second <= d)
      md = max(md, vd[vd.size() - 1].first);
    if (vc.size() != 0 && vc[vc.size() - 1].second <= c)
      mc = max(mc, vc[vc.size() - 1].first);
  }
  sort(vc.begin(), vc.end(), cmp);
  sort(vd.begin(), vd.end(), cmp);
  l = vc.size() - 1;
  for (int i = 0; i < vc.size(); i++) {
    if (i != 0)
      maxc[i] = max(maxc[i - 1], vc[i].first);
    else
      maxc[i] = vc[i].first;
    while (l != -1 && vc[i].second + vc[l].second > c) l--;
    if (l == -1) break;
    if (l < i) {
      maxy = max(maxy, vc[i].first + maxc[l]);
    } else if (i != 0) {
      maxy = max(maxy, vc[i].first + maxc[i - 1]);
    }
  }
  l = vd.size() - 1;
  for (int i = 0; i < vd.size(); i++) {
    if (i != 0)
      maxd[i] = max(maxd[i - 1], vd[i].first);
    else
      maxd[i] = vd[i].first;
    while (l != -1 && vd[i].second + vd[l].second > c) l--;
    if (l == -1) break;
    if (l < i) {
      maxy = max(maxy, vd[i].first + maxd[l]);
    } else if (i != 0) {
      maxy = max(maxy, vd[i].first + maxd[i - 1]);
    }
  }
  if (maxy == -1 && (md == -1 || mc == -1))
    cout << 0;
  else if (maxy == -1)
    cout << md + mc;
  else if (md == -1 || mc == -1)
    cout << maxy;
  else
    cout << max(maxy, md + mc);
  return 0;
}
