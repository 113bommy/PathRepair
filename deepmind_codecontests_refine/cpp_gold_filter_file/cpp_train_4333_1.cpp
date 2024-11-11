#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, w, h;
  cin >> n >> w >> h;
  map<int, vector<pair<pair<int, int>, int> > > gr;
  vector<pair<int, int> > ans(n);
  for (int i = 0; i < n; i++) {
    int g, p, t;
    cin >> g >> p >> t;
    gr[p - t].push_back(make_pair(make_pair(g, p), i));
  }
  for (auto& cgr : gr) {
    sort((cgr.second).begin(), (cgr.second).end(),
         [&](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
           if (a.first.first != b.first.first)
             return (a.first.first == 2);
           else
             return (a.first.first == 2 ? a.first.second > b.first.second
                                        : a.first.second < b.first.second);
         });
    vector<int> xx, yy;
    for (auto& cur : cgr.second)
      if (cur.first.first == 1)
        xx.push_back(cur.first.second);
      else
        yy.push_back(cur.first.second);
    sort((xx).begin(), (xx).end());
    sort((yy).rbegin(), (yy).rend());
    for (int i = 0; i < xx.size(); i++) {
      ans[cgr.second[i].second].first = xx[i];
      ans[cgr.second[i].second].second = h;
    }
    for (int i = 0; i < yy.size(); i++) {
      ans[cgr.second[i + xx.size()].second].first = w;
      ans[cgr.second[i + xx.size()].second].second = yy[i];
    }
  }
  for (auto& x : ans) cout << x.first << ' ' << x.second << endl;
  return 0;
}
