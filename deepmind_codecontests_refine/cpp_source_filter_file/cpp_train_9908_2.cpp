#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int n, w, k;
  cin >> n >> w >> k;
  unordered_map<int, vector<pair<long long, long long>>> m;
  for (int i = 0; i < w; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    m[a].push_back(make_pair(c, b));
    m[b].push_back(make_pair(c, a));
  }
  for (auto i : m) {
    sort(m[i.first].begin(), m[i.first].end());
  }
  set<pair<long long, pair<long long, long long>>> s;
  int cou = 0;
  map<pair<long long, long long>, int> mark;
  for (auto i : m) {
    for (auto j : i.second) {
      if (s.size() <= 100 * k)
        s.insert(make_pair(j.first, make_pair(j.second, i.first)));
      else {
        auto x = s.rbegin();
        auto q = *x;
        if (q.first > j.first) {
          s.erase(q);
          s.insert(make_pair(j.first, make_pair(j.second, i.first)));
        } else if (q.first == j.first) {
          s.insert(make_pair(j.first, make_pair(j.second, i.first)));
        }
      }
    }
  }
  while (cou != k - 1) {
    auto x = s.begin();
    pair<long long, pair<long long, long long>> p = *x;
    s.erase(x);
    if (!mark.count(p.second)) cou++;
    mark[p.second]++;
    mark[make_pair(p.second.second, p.second.first)]++;
    int node = p.second.first;
    int src = p.second.second;
    for (auto i : m[node]) {
      if (i.second != src) {
        if (!mark.count(make_pair(src, i.second))) {
          if (s.size() >= 100 * k) {
            auto r = s.rbegin();
            auto q = *r;
            if ((long long)(p.first + i.first) < q.first) {
              s.insert(make_pair((long long)(p.first + i.first),
                                 make_pair(i.second, src)));
              s.erase(q);
            }
          } else {
            s.insert(make_pair((long long)(p.first + i.first),
                               make_pair(i.second, src)));
          }
        }
      }
    }
  }
  cout << (*s.begin()).first;
}
