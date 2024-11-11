#include <bits/stdc++.h>
using namespace std;
long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}
inline int myrand() { return abs((rand() << 15) ^ rand()); }
inline int rnd(int x) { return myrand() % x; }
const int INF = (int)1.01e9;
const long double EPS = 1e-9;
const long double PI = acos(-1.0L);
void precalc() {}
int n, m;
vector<vector<int> > a;
bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return 0;
  }
  a = vector<vector<int> >(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  return 1;
}
const int maxn = (int)1e6 + 10;
int minr[maxn], minc[maxn];
int pr[maxn], w[maxn];
int get(int v) {
  if (pr[v] == v) {
    return v;
  }
  return pr[v] = get(pr[v]);
}
void myUnion(int a, int b) {
  a = get(a), b = get(b);
  if (a == b) {
    return;
  }
  if (w[a] == w[b]) {
    ++w[a];
  }
  if (w[a] < w[b]) {
    swap(a, b);
  }
  pr[b] = a;
}
void solve() {
  for (int i = 0; i < n; ++i) {
    minr[i] = 0;
  }
  for (int i = 0; i < m; ++i) {
    minc[i] = 0;
  }
  auto ids = a;
  int cntv = 0;
  vector<pair<int, int> > tosort;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ids[i][j] = cntv++;
      tosort.push_back(make_pair(a[i][j], ids[i][j]));
    }
  }
  for (int i = 0; i < cntv; ++i) {
    pr[i] = i, w[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    map<int, int> know;
    for (int j = 0; j < m; ++j) {
      int x = a[i][j];
      auto iter = know.find(x);
      if (iter == know.end()) {
        know[x] = ids[i][j];
      } else {
        myUnion(ids[i][j], iter->second);
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    map<int, int> know;
    for (int j = 0; j < n; ++j) {
      int x = a[j][i];
      auto iter = know.find(x);
      if (iter == know.end()) {
        know[x] = ids[j][i];
      } else {
        myUnion(ids[j][i], iter->second);
      }
    }
  }
  vector<vector<int> > repr(cntv);
  for (int i = 0; i < cntv; ++i) {
    repr[get(i)].push_back(i);
  }
  sort(tosort.begin(), tosort.end());
  auto ans = a;
  for (int it = 0; it < ((int)(tosort).size()); ++it) {
    int id = tosort[it].second;
    if (pr[id] != id) {
      continue;
    }
    int got = 0;
    for (int vid : repr[id]) {
      got = max(got, minr[vid / m]);
      got = max(got, minc[vid % m]);
    }
    ++got;
    for (int vid : repr[id]) {
      ans[vid / m][vid % m] = got;
      minr[vid / m] = max(minc[vid / m], got);
      minc[vid % m] = max(minr[vid % m], got);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      printf("%d%c", ans[i][j], " \n"[j == m - 1]);
    }
  }
}
int main() {
  srand(rdtsc());
  precalc();
  while (1) {
    if (!read()) {
      break;
    }
    solve();
  }
  return 0;
}
