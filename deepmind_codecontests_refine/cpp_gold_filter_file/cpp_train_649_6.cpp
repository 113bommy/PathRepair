#include <bits/stdc++.h>
using namespace std;
inline void pisz(int n) { printf("%d\n", n); }
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, -1, 0, 1};
const int drr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dcc[8] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename TT>
ostream& operator<<(ostream& s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream& operator<<(ostream& s, vector<T> t) {
  for (int i = 0; i < ((int)((t).size())); i++) s << t[i] << " ";
  return s;
}
class UnionFind {
 private:
  vector<int> rank, p;

 public:
  UnionFind(int n) {
    for (int i = 0; i < n; i++) p.push_back(i);
    rank.assign(n, 0);
  }
  int findSet(int s) { return (p[s] == s) ? s : (p[s] = findSet(p[s])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;
    int x = findSet(i), y = findSet(j);
    if (rank[x] > rank[y])
      p[y] = x;
    else {
      p[x] = y;
      if (rank[x] == rank[y]) rank[y]++;
    }
  }
};
bool fcomp(double A, double B) {
  double EPSILON = numeric_limits<double>::epsilon();
  double diff = A - B;
  return fabs(diff) < EPSILON;
}
double x_y(int x1, int y1, int x2, int y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> f(11, 0), f2(11, 0);
  for (int i = 0; i < s.size(); i++) {
    f[s[i] - '0']++;
    f2[s[i] - '0']++;
  }
  vector<int> ans(n, -1), ans2(n, -1);
  int mx = 0;
  vector<pair<int, int> > ck;
  for (int i = 0; i < 10; i++) {
    if (f[i] > 0 && f[10 - i] > 0) ck.push_back({i, 10 - i});
  }
  for (int i = 0; i < ck.size(); i++) {
    int v1 = ck[i].first, v2 = ck[i].second, id = n - 2, ct = 1;
    vector<int> tmpf = f, tmpf2 = f2, curans(n, -1), curans2(n, -1);
    tmpf[v1]--;
    tmpf2[v2]--;
    curans[n - 1] = v1;
    curans2[n - 1] = v2;
    for (int j = 0; j < 10; j++) {
      while (tmpf[j] > 0 && tmpf2[9 - j] > 0) {
        tmpf[j]--;
        tmpf2[9 - j]--;
        curans[id] = j;
        curans2[id--] = 9 - j;
        ct++;
      }
    }
    vector<int> fans(n, -1), fans2(n, -1);
    int fid = n - 1;
    while (tmpf[0] && tmpf2[0]) {
      fans[fid] = 0;
      fans2[fid--] = 0;
      tmpf[0]--;
      tmpf2[0]--;
      ct++;
    }
    int nid = id;
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < tmpf[j]; k++) {
        curans[nid] = j;
        nid--;
      }
    }
    nid = id;
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < tmpf2[j]; k++) {
        curans2[nid] = j;
        nid--;
      }
    }
    nid = 0;
    for (int j = n - 1 - fid; j < n; j++) fans[nid++] = curans[j];
    nid = 0;
    for (int j = n - 1 - fid; j < n; j++) fans2[nid++] = curans2[j];
    if (ct > mx) {
      mx = ct;
      ans = fans;
      ans2 = fans2;
    }
  }
  if (ck.size() == 0) {
    vector<int> fans(n, -1), fans2(n, -1);
    int id = n - 1;
    while (f[0] && f2[0]) {
      fans[id] = 0;
      fans2[id--] = 0;
      f[0]--;
      f2[0]--;
    }
    int nid = 0;
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < f[j]; k++) {
        fans[nid] = j;
        nid++;
      }
    }
    nid = 0;
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < f2[j]; k++) {
        fans2[nid] = j;
        nid++;
      }
    }
    ans = fans;
    ans2 = fans2;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i];
  }
  cout << endl;
  for (int i = 0; i < n; i++) cout << ans2[i];
  cout << endl;
  return 0;
}
