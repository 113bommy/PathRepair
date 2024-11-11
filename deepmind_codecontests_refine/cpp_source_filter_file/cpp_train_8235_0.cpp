#include <bits/stdc++.h>
using namespace std;
int a, b;
void output(vector<pair<int, int>> ans) {
  int aw = 0, bw = 0;
  for (auto p : ans)
    if (p.first > p.second)
      ++aw;
    else
      ++bw;
  cout << aw << ":" << bw << '\n';
  for (auto p : ans) cout << p.first << ":" << p.second << " ";
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m;
  cin >> m;
  while (m--) {
    cin >> a >> b;
    [&]() {}();
    [&]() {}();
    auto go = [&](vector<pair<int, int>> v) -> bool {
      int aa = a, bb = b;
      for (auto p : v) aa -= p.first, bb -= p.second;
      if (aa < 0 || bb < 0) return 0;
      int cantie = -1;
      if (aa > bb) {
        for (int i = int(v.size()) - 1; i >= 0; --i) {
          auto &p = v[i];
          if (p.first == 0) {
            while (aa > bb && p.first < p.second - 2) {
              --aa;
              ++p.first;
            }
            if (p.first == p.second - 2) cantie = i;
          }
        }
      } else if (aa < bb) {
        for (int i = int(v.size()) - 1; i >= 0; --i) {
          auto &p = v[i];
          if (p.second == 0) {
            while (aa < bb && p.second < p.first - 2) {
              --bb;
              ++p.second;
            }
            if (p.second == p.first - 2) cantie = i;
          }
        }
      }
      if (aa != bb) return 0;
      if (aa == 0) return output(v), 1;
      if (cantie != -1) {
        v[cantie].first += aa;
        v[cantie].second += aa;
        output(v);
        return 1;
      }
      while (aa && !cantie) {
        int aput = -1, bput = -1;
        for (int i = 0; i < int(v.size()); ++i) {
          auto &p = v[i];
          if (p.second == (i == 4 ? 15 : 25)) {
            if (p.first < (i == 4 ? 13 : 23)) {
              aput = i;
            }
          }
          if (p.first == (i == 4 ? 15 : 25)) {
            if (p.second < (i == 4 ? 13 : 23)) {
              bput = i;
            }
          }
        }
        if (aput == -1 || bput == -1) return 0;
        --aa;
        ++v[aput].first;
        ++v[bput].second;
        if (v[aput].first == v[aput].second - 2) cantie = aput;
        if (v[bput].second == v[bput].first - 2) cantie = bput;
      }
      if (aa == 0) return output(v), 1;
      if (cantie != -1) {
        v[cantie].first += aa;
        v[cantie].second += aa;
        output(v);
        return 1;
      }
      return 0;
    };
    vector<pair<int, int>> v;
    v.emplace_back(25, 0);
    v.emplace_back(25, 0);
    v.emplace_back(25, 0);
    if (go(v)) continue;
    v.clear();
    v.emplace_back(25, 0);
    v.emplace_back(25, 0);
    v.emplace_back(0, 25);
    v.emplace_back(25, 0);
    if (go(v)) continue;
    v.clear();
    v.emplace_back(25, 0);
    v.emplace_back(25, 0);
    v.emplace_back(0, 25);
    v.emplace_back(0, 25);
    v.emplace_back(15, 0);
    if (go(v)) continue;
    v.clear();
    v.emplace_back(25, 0);
    v.emplace_back(25, 0);
    v.emplace_back(0, 25);
    v.emplace_back(0, 25);
    v.emplace_back(0, 15);
    if (go(v)) continue;
    v.clear();
    v.emplace_back(25, 0);
    v.emplace_back(0, 25);
    v.emplace_back(0, 25);
    v.emplace_back(0, 25);
    if (go(v)) continue;
    v.clear();
    v.emplace_back(0, 25);
    v.emplace_back(0, 25);
    v.emplace_back(0, 25);
    if (go(v)) continue;
    v.clear();
    cout << "Impossible" << '\n';
  }
}
