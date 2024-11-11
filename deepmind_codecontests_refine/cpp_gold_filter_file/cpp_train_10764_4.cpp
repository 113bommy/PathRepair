#include <bits/stdc++.h>
using namespace std;
struct xy {
  long long x;
  long long y;
  xy(long long a, long long b) {
    x = a;
    y = b;
  }
  xy() {
    x = -1E10;
    y = -1E10;
  }
};
vector<vector<int> > ans;
vector<pair<long long, xy> > stat;
vector<xy> glist;
long long n, m, k;
long long dist(xy a, xy b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
long long answer(long long a, long long b) {
  vector<char> cou(m, false);
  for (int i = 0; i < ans[a].size(); i++) {
    cou[ans[a][i]] = !cou[ans[a][i]];
  }
  for (int i = 0; i < ans[b].size(); i++) {
    cou[ans[b][i]] = !cou[ans[b][i]];
  }
  long long locans = 0;
  for (int i = 0; i < m; i++) {
    locans += cou[i];
  }
  return locans;
}
int main() {
  cin >> n >> m >> k;
  ans = vector<vector<int> >(n);
  glist = vector<xy>(n);
  stat = vector<pair<long long, xy> >(m);
  for (int i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    glist[i] = xy(a, b);
  }
  for (int i = 0; i < m; i++) {
    long long a, b, r;
    cin >> r >> a >> b;
    stat[i] = {r, xy(a, b)};
    for (int j = 0; j < n; j++) {
      if (stat[i].first * stat[i].first > dist(stat[i].second, glist[j])) {
        ans[j].push_back(i);
      }
    }
  }
  for (int i = 0; i < k; i++) {
    long long q, e;
    cin >> q >> e;
    cout << answer(q - 1, e - 1) << endl;
  }
  return 0;
}
