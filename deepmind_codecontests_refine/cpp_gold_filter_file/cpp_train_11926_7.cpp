#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> g;
vector<vector<pair<int, int>>> chains;
vector<vector<long long>> pxsum;
vector<char> sw;
int x11, y11, x22, y22;
bool into(pair<int, int> &p) {
  return !(p.first < x11 - 1 || p.first > x22 - 1 || p.second < y11 - 1 ||
           p.second > y22 - 1);
}
bool into2(pair<int, int> &p) {
  return !(p.first <= x11 - 1 || p.first >= x22 - 1 || p.second <= y11 - 1 ||
           p.second >= y22 - 1);
}
long long getsum(int id, int b, int e) {
  return pxsum[id][e] - (b > 0 ? pxsum[id][b - 1] : 0);
}
int main(int argc, char *argv[]) {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  g.resize(n, vector<pair<int, int>>(m));
  chains.resize(k);
  sw.resize(k);
  pxsum.resize(k);
  for (int i = 0; i < k; ++i) {
    int m;
    scanf("%d", &m);
    pxsum[i].resize(m);
    for (int j = 0; j < m; ++j) {
      int x, y, w;
      scanf("%d%d%d", &x, &y, &w);
      --x;
      --y;
      g[x][y] = make_pair(i + 1, j + 1);
      chains[i].push_back(make_pair(x, y));
      pxsum[i][j] = w;
      pxsum[i][j] += (j > 0 ? pxsum[i][j - 1] : 0);
    }
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    char s[10];
    scanf("%s", s);
    if (s[0] == 'A') {
      vector<pair<int, int>> d;
      vector<char> mr(k);
      scanf("%d%d%d%d", &x11, &y11, &x22, &y22);
      long long sum = 0;
      for (int y = y11; y <= y22; ++y) {
        if (g[x11 - 1][y - 1].first != 0) {
          d.push_back(g[x11 - 1][y - 1]);
        }
        if (g[x22 - 1][y - 1].first != 0) {
          d.push_back(g[x22 - 1][y - 1]);
        }
      }
      for (int x = x11 + 1; x <= x22 - 1; ++x) {
        if (g[x - 1][y11 - 1].first != 0) {
          d.push_back(g[x - 1][y11 - 1]);
        }
        if (g[x - 1][y22 - 1].first != 0) {
          d.push_back(g[x - 1][y22 - 1]);
        }
      }
      sort(d.begin(), d.end());
      for (int j = 0; j < d.size(); ++j) {
        int id = d[j].first;
        mr[id - 1] = 1;
        if (sw[id - 1]) {
          continue;
        }
        vector<int> pt;
        if (d[j].second != 1) {
          pt.push_back(1);
        }
        while (j < d.size() && d[j].first == id) {
          if (pt.empty() || pt.back() != d[j].second) {
            pt.push_back(d[j].second);
          }
          j++;
        }
        j--;
        if (pt.back() != chains[id - 1].size()) {
          pt.push_back(chains[id - 1].size());
        }
        for (int k = 0; k < pt.size() - 1; k++) {
          int f = pt[k];
          sum +=
              (into(chains[id - 1][f - 1]) ? getsum(id - 1, f - 1, f - 1) : 0);
          int nx = pt[k + 1];
          if (into(chains[id - 1][f]) && f <= nx - 2) {
            sum += getsum(id - 1, f, nx - 2);
          }
        }
        int f = pt.back();
        sum += (into(chains[id - 1][f - 1]) ? getsum(id - 1, f - 1, f - 1) : 0);
      }
      for (int q = 0; q < k; ++q) {
        if (mr[q] == 0 && into2(chains[q][0]) && into2(chains[q].back())) {
          if (sw[q]) {
            continue;
          }
          sum += getsum(q, 0, chains[q].size() - 1);
        }
      }
      printf("%I64d\n", sum);
      sum = 0;
    } else {
      int id;
      scanf("%d", &id);
      sw[id - 1] = 1 - sw[id - 1];
    }
  }
  return 0;
}
