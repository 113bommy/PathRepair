#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, k, x[N], R[N], q[N], a, b;
vector<int> Q;
vector<int> v[N], seg[N];
vector<pair<int, int> > v2, v3;
long long ans = 0, d = 0;
int iq, Idx;
int update(int s, int e, int idx) {
  if (s > Idx || e < Idx) return seg[iq][idx];
  if (s == e) return ++seg[iq][idx];
  return seg[iq][idx] = update(s, ((s + e) >> 1), (idx << 1)) +
                        update(((s + e) >> 1) + 1, e, (idx << 1) + 1);
}
int l, r;
int getsum(int s, int e, int idx) {
  if (s > r || e < l) return 0;
  if (s >= l && e <= r) return seg[iq][idx];
  return getsum(s, ((s + e) >> 1), (idx << 1)) +
         getsum(((s + e) >> 1) + 1, e, (idx << 1) + 1);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &x[i], &R[i], &q[i]);
    Q.push_back(q[i]);
  }
  sort(Q.begin(), Q.end());
  Q.resize(unique(Q.begin(), Q.end()) - Q.begin());
  for (int i = 0; i < n; i++) {
    q[i] = lower_bound(Q.begin(), Q.end(), q[i]) - Q.begin();
    v[q[i]].push_back(x[i]);
    v2.push_back(make_pair(x[i], i));
    v3.push_back(make_pair(x[i] - R[i], i));
  }
  sort(v2.begin(), v2.end());
  sort(v3.begin(), v3.end());
  for (int i = 0; i < (int)Q.size(); i++) {
    sort(v[i].begin(), v[i].end());
    v[i].resize(unique(v[i].begin(), v[i].end()) - v[i].begin());
    seg[i].resize((int)v[i].size() * 4, 0);
  }
  int j = 0;
  for (int i = 0; i < (int)v2.size(); i++) {
    while (j < (int)v3.size() && v3[j].first <= v2[i].first) {
      iq = q[v3[j].second];
      Idx = lower_bound(v[iq].begin(), v[iq].end(), x[v3[j].second]) -
            v[iq].begin();
      update(0, (int)v[iq].size() - 1, 1);
      j++;
    }
    a = q[v2[i].second];
    while (a < (int)Q.size() && Q[a] - Q[q[v2[i].second]] <= k) {
      l = lower_bound(v[a].begin(), v[a].end(), x[v2[i].second]) - v[a].begin();
      r = upper_bound(v[a].begin(), v[a].end(),
                      x[v2[i].second] + R[v2[i].second]) -
          v[a].begin() - 1;
      if (r >= l) {
        iq = a;
        ans += getsum(0, (int)v[a].size() - 1, 1);
      }
      if (l < (int)v[a].size() && v[a][l] == x[v2[i].second]) {
        r = l;
        d += getsum(0, (int)v[a].size() - 1, 1);
      }
      a++;
    }
    a = q[v2[i].second] - 1;
    while (a >= 0 && Q[q[v2[i].second]] - Q[a] <= k) {
      l = lower_bound(v[a].begin(), v[a].end(), x[v2[i].second]) - v[a].begin();
      r = upper_bound(v[a].begin(), v[a].end(),
                      x[v2[i].second] + R[v2[i].second]) -
          v[a].begin() - 1;
      if (r >= l) {
        iq = a;
        ans += getsum(0, (int)v[a].size() - 1, 1);
      }
      if (l < (int)v[a].size() && v[a][l] == x[v2[i].second]) {
        r = l;
        d += getsum(0, (int)v[a].size() - 1, 1);
      }
      a--;
    }
  }
  d -= n;
  cout << ans - n - d / 2 << endl;
  return 0;
}
