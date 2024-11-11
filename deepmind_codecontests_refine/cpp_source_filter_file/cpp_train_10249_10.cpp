#include <bits/stdc++.h>
using namespace std;
int n, s;
vector<pair<int, int> > v[100 + 10];
int spd[2], crd[2];
pair<pair<int, int>, int> md[200 + 10];
int calc(int a, int b) {
  int res = 0;
  int len = 0;
  int cum = v[a][0].first;
  for (int i = 1, sz = v[a].size(); i < sz; ++i) {
    md[len++] = make_pair(make_pair(cum, v[a][i].second), 0);
    cum += v[a][i].first;
  }
  md[len++] = make_pair(make_pair(cum, 0), 0);
  cum = v[b][0].first;
  for (int i = 1, sz = v[b].size(); i < sz; ++i) {
    md[len++] = make_pair(make_pair(cum, v[b][i].second), 1);
    cum += v[b][i].first;
  }
  md[len++] = make_pair(make_pair(cum, 0), 1);
  sort(md, md + len);
  spd[0] = v[a][0].second, spd[1] = v[b][0].second;
  crd[0] = crd[1] = 0;
  int state = -1;
  int prevtime = 0;
  for (int i = 0; i < len;) {
    crd[0] += (md[i].first.first - prevtime) * spd[0];
    crd[1] += (md[i].first.first - prevtime) * spd[1];
    bool flag = false;
    spd[md[i].second] = md[i].first.second;
    if (i < len && md[i].first.first == md[i + 1].first.first) {
      flag = true;
      spd[md[i + 1].second] = md[i + 1].first.second;
    }
    if (crd[0] > crd[1]) {
      if (state == 1) ++res;
      state = 0;
    } else if (crd[0] < crd[1]) {
      if (state == 0) ++res;
      state = 1;
    }
    prevtime = md[i].first.second;
    ++i;
    if (flag) ++i;
  }
  return res;
}
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; ++j) {
      int sp, tm;
      scanf("%d %d", &sp, &tm);
      v[i].push_back(make_pair(tm, sp));
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      ans += calc(i, j);
    }
  }
  cout << ans;
  return 0;
}
