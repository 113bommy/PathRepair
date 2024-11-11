#include <bits/stdc++.h>
using namespace std;
const double Pi = acos((double)-1);
const long long oo((long long)1e+9);
template <typename T>
inline ostream &operator<<(ostream &out, const vector<T> &v) {
  for (auto &it : v) out << it << ' ';
  return out;
}
template <typename T>
inline istream &operator>>(istream &in, vector<T> &v) {
  for (auto &it : v) in >> it;
  return in;
}
template <typename T1, typename T2>
inline ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << p.first << ' ' << p.second << ' ';
  return out;
}
template <typename T1, typename T2>
inline istream &operator>>(istream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T>
inline ostream &operator<<(ostream &out, const set<T> &p) {
  for (auto &i : p) out << i << ' ';
  return out;
}
template <typename T>
inline istream &operator>(istream &in, T &p) {
  return in >> p;
}
template <typename T>
inline ostream &operator<(ostream &out, const T &p) {
  return out << p;
}
template <typename T1, typename T2>
inline pair<T1 &, T2 &> unzip_pair(T1 &p1, T2 &p2) {
  return pair<T1 &, T2 &>(p1, p2);
}
template <typename T>
inline T min(const vector<T> &p) {
  T ans = p[0];
  for (auto &i : p) ans = min(ans, i);
  return ans;
}
template <typename T>
inline T max(const vector<T> &p) {
  T ans = p[0];
  for (auto &i : p) ans = max(ans, i);
  return ans;
}
int n, m;
vector<long long> w, c;
vector<vector<pair<int, int>>> nx;
long long s, cur = 0;
bool cmp(const pair<pair<int, int>, int> p1,
         const pair<pair<int, int>, int> p2) {
  return w[p1.second] < w[p2.second];
}
int snm[200200];
int getX(int a) {
  if (snm[a] != a) snm[a] = getX(snm[a]);
  return snm[a];
}
void merge(int a, int b) {
  a = getX(a);
  b = getX(b);
  snm[a] = b;
}
vector<vector<int>> lca, ans;
long long tin[200200], tout[200200];
bool isA(int a, int b) { return tin[a] <= tin[b] && tout[a] >= tout[b]; }
long long build(int v, int reserved_1, int cr, long long t) {
  tin[v] = t;
  if (reserved_1 != -1) {
    lca[v].push_back(reserved_1);
    ans[v].push_back(cr);
    int last = reserved_1;
    while (lca[last].size() >= lca[v].size()) {
      int h = lca[v].size() - 1;
      ans[v].push_back(ans[v].back());
      if (w[ans[v][h + 1]] < w[ans[lca[v][h]][h]]) {
        w[ans[v][h + 1]] = w[ans[lca[v][h]][h]];
      }
      lca[v].push_back(lca[last][h]);
      last = lca[v].back();
    }
  }
  for (auto i : nx[v]) {
    if (i.first == reserved_1) continue;
    t = build(i.first, v, i.second, t + 1);
  }
  tout[v] = t;
  return t + 1;
}
int getH(int a, int b) {
  int cur = -1;
  int p = lca[b].size();
  while (!isA(b, a)) {
    p = min(p, (int)lca[b].size());
    p = max(0, p - 1);
    while (p > 0 && isA(lca[b][p], a)) p--;
    if (cur == -1 || w[cur] < w[ans[b][p]]) {
      cur = ans[b][p];
    }
    b = lca[b][p];
  }
  return cur;
}
void setAns(int v, int reserved_1, int bl) {
  for (auto i : nx[v]) {
    if (i.first == reserved_1) continue;
    if (i.second != bl) cout < i.second + 1 < ' ' < w[i.second] < '\n';
    setAns(i.first, v, bl);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout < fixed < setprecision(7);
  for (int i = 0; i < 200200; i++) snm[i] = i;
  cin > n > m;
  (w).resize(m);
  (c).resize(m);
  (nx).resize(n);
  (lca).resize(n);
  (ans).resize(n);
  cin > w > c;
  vector<pair<pair<int, int>, int>> ms;
  for (int i = 0; i < (m); i++) {
    int a, b;
    cin > a > b;
    a--;
    b--;
    ms.push_back({{a, b}, i});
  }
  sort((ms).begin(), (ms).end(), cmp);
  cin > s;
  for (int i = 0; i < (m); i++) {
    if (getX(ms[i].first.first) != getX(ms[i].first.second)) {
      merge(ms[i].first.first, ms[i].first.second);
      nx[ms[i].first.first].push_back({ms[i].first.second, ms[i].second});
      nx[ms[i].first.second].push_back({ms[i].first.first, ms[i].second});
      cur += w[ms[i].second];
    }
  }
  build(0, -1, -1, 0);
  long long cur_ans = 1e+18, bl = -1, an = -1;
  for (int i = 0; i < (m); i++) {
    long long ca = cur + w[ms[i].second] - s / c[ms[i].second];
    int p1 = getH(ms[i].first.first, ms[i].first.second);
    int p2 = getH(ms[i].first.second, ms[i].first.first);
    if (p1 == -1) p1 = p2;
    if (p2 != -1 && w[p1] < w[p2]) p1 = p2;
    ca -= w[p1];
    if (cur_ans > ca) {
      cur_ans = ca;
      bl = p1;
      an = ms[i].second;
    }
  }
  cout < cur_ans < '\n';
  cout < an + 1 < ' ' < w[an] - s / c[an] < '\n';
  setAns(0, -1, bl);
  return 0;
}
