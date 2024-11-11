#include <bits/stdc++.h>
using namespace std;
int oo = (int)1e9;
vector<string> vs;
int dp2[501][26][26];
inline int getCost(int idx, int c1, int c2) {
  int diff = 0;
  for (int i = 0; i < (int)vs[idx].size(); ++i) {
    diff += (i & 1 ? (vs[idx][i] - 'a') != c2 : (vs[idx][i] - 'a') != c1);
  }
  return diff;
}
int dp[501][26][26];
vector<pair<vector<int>, vector<int> > > cs;
inline int calc(int c1, int c2, int r) {
  if (r == (int)vs.size()) return 0;
  int &ret = dp[r][c1][c2];
  if (ret != -1) return ret;
  ret = oo;
  for (int i = 0; i < (int)cs[r].first.size(); ++i) {
    if (cs[r].first[i] == c1) continue;
    for (int j = 0; j < (int)cs[r].second.size(); ++j) {
      if (cs[r].second[j] == c2 || cs[r].first[i] == cs[r].second[j]) continue;
      ret = min(ret, calc(cs[r].first[i], cs[r].second[j], r + 1) +
                         dp2[r][cs[r].first[i]][cs[r].second[j]]);
    }
  }
  return ret;
}
inline void print(int c1, int c2, int r) {
  if (r == (int)vs.size()) return;
  int res = calc(c1, c2, r);
  for (int i = 0; i < (int)cs[r].first.size(); ++i) {
    if (cs[r].first[i] == c1) continue;
    for (int j = 0; j < (int)cs[r].second.size(); ++j) {
      if (cs[r].second[j] == c2 || cs[r].first[i] == cs[r].second[j]) continue;
      if (calc(cs[r].first[i], cs[r].second[j], r + 1) +
              dp2[r][cs[r].first[i]][cs[r].second[j]] ==
          res) {
        for (int k = 0; k < (int)vs[r].size(); ++k) {
          vs[r][k] = (k & 1 ? (char)(cs[r].second[j] + 'a')
                            : (char)(cs[r].first[i] + 'a'));
        }
        print(cs[r].first[i], cs[r].second[j], r + 1);
        return;
      }
    }
  }
}
inline int calc1(int idx, int p) {
  if (idx == (int)vs.size()) return 0;
  int &ret = dp[idx][p][0];
  if (ret != -1) return ret;
  ret = oo;
  for (int i = 0; i < (int)cs[idx].first.size(); ++i) {
    if (p == cs[idx].first[i]) continue;
    ret = min(ret, calc1(idx + 1, cs[idx].first[i]) +
                       int((vs[idx][0] - 'a') != cs[idx].first[i]));
  }
  return ret;
}
inline void print1(int idx, int p) {
  if (idx == (int)vs.size()) return;
  int ret = calc1(idx, p);
  for (int i = 0; i < (int)cs[idx].first.size(); ++i) {
    if (p == cs[idx].first[i]) continue;
    if (calc1(idx + 1, cs[idx].first[i]) +
            int((vs[idx][0] - 'a') != cs[idx].first[i]) ==
        ret) {
      vs[idx][0] = (cs[idx].first[i] + 'a');
      print1(idx + 1, cs[idx].first[i]);
      return;
    }
  }
  return;
}
char sst[502];
int cCst[501][26][2];
int main() {
  memset(dp, -1, sizeof dp);
  int n, m;
  scanf("%d%d", &n, &m);
  cs = vector<pair<vector<int>, vector<int> > >(n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", sst);
    vs.push_back(sst);
  }
  for (int i = 0; i < (int)vs.size(); ++i)
    for (int j = 0; j < (int)vs[i].size(); ++j)
      cCst[i][vs[i][j] - 'a'][j & 1]++;
  for (int i = 0; i < (int)vs.size(); ++i) {
    vector<pair<int, int> > frq0, frq1;
    for (int j = 0; j < 26; ++j) {
      frq0.push_back(make_pair(cCst[i][j][0], j));
      frq1.push_back(make_pair(cCst[i][j][1], j));
    }
    sort(frq0.rbegin(), frq0.rend());
    sort(frq1.rbegin(), frq1.rend());
    for (int j = 0; j < 4; ++j) {
      cs[i].first.push_back(frq0[j].second);
      cs[i].second.push_back(frq1[j].second);
    }
  }
  for (int i = 0; i < (int)vs.size(); ++i)
    for (int j = 0; j < 26; ++j)
      for (int k = 0; k < 26; ++k)
        dp2[i][j][k] = m - cCst[i][j][0] - cCst[i][k][1];
  if (m == 1) {
    int res = oo;
    for (int i = 0; i < (int)cs[0].first.size(); ++i) {
      res = min(res, calc1(1, cs[0].first[i]) +
                         int((vs[0][0] - 'a') != cs[0].first[i]));
    }
    printf("%d\n", res);
    for (int i = 0; i < (int)cs[0].first.size(); ++i) {
      if (res ==
          calc1(1, cs[0].first[i]) + int((vs[0][0] - 'a') != cs[0].first[i])) {
        vs[0][0] = (cs[0].first[i] + 'a');
        print1(1, cs[0].first[i]);
        break;
      }
    }
    for (int i = 0; i < (int)vs.size(); ++i) printf("%s\n", vs[i].c_str());
    return 0;
  }
  int res = oo;
  for (int i = 0; i < (int)cs[0].first.size(); ++i) {
    for (int j = 0; j < (int)cs[0].second.size(); ++j) {
      if (cs[0].first[i] == cs[0].second[j]) continue;
      res = min(res, calc(cs[0].first[i], cs[0].second[j], 1) +
                         dp2[0][cs[0].first[i]][cs[0].second[j]]);
    }
  }
  printf("%d\n", res);
  for (int i = 0; i < (int)cs[0].first.size(); ++i) {
    for (int j = 0; j < (int)cs[0].second.size(); ++j) {
      if (cs[0].first[i] == cs[0].second[j]) continue;
      if (calc(cs[0].first[i], cs[0].second[j], 1) +
              dp2[0][cs[0].first[i]][cs[0].second[j]] ==
          res) {
        for (int k = 0; k < (int)vs[0].size(); ++k)
          vs[0][k] = (k & 1 ? (char)(cs[0].second[j] + 'a')
                            : (char)(cs[0].first[i] + 'a'));
        print(cs[0].first[i], cs[0].second[j], 1);
        goto bara;
      }
    }
  }
bara:;
  for (int i = 0; i < (int)vs.size(); ++i) printf("%s\n", vs[i].c_str());
  return 0;
}
