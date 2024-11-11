#include <bits/stdc++.h>
using namespace std;
int t, n, bad, w[5000 * 1000], g[5000 * 1000], p[5000 * 1000], ans[5000 * 1000],
    d[5000 * 1000], cnt;
pair<int, int> buf[5000 * 1000];
vector<pair<int, int> > v, e;
map<int, vector<pair<int, int> > > m;
void go(int x) {
  if (w[x]) return;
  w[x] = 1;
  d[cnt++] = x;
  go(p[x]);
}
void place(int x) {
  if (w[x] == 2) return;
  w[x] = 2;
  ans[x] = g[cnt++];
  place(p[x]);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  for (int i = 1; i <= n; i++) {
    if (!w[i]) {
      cnt = 0;
      go(i);
      if (cnt & 1) {
        for (int j = 0; j < cnt; j++) g[j] = d[(cnt + j - cnt / 2) % cnt];
        cnt = 0;
        place(i);
      } else {
        v.clear();
        for (int j = 0, t = i; j < cnt; j++, t = p[t]) {
          v.push_back(make_pair(d[j], t));
        }
        if (m[cnt].empty()) {
          bad++;
          m[cnt] = v;
        } else {
          bad--;
          e = m[cnt];
          for (int j = 0; j < cnt; j++) {
            ans[v[j].second] = e[j].first;
            ans[e[j].second] = v[(j + 1) % cnt].first;
          }
          m[cnt].clear();
        }
      }
    }
  }
  if (bad) {
    cout << -1;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
    d[i] = ans[ans[i]];
  }
}
