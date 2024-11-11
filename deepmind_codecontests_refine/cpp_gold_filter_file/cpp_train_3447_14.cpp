#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
ostream& operator<<(ostream& out, const pair<A, B>& a) {
  return out << "(" << a.first << ", " << a.second << ")";
}
template <class A>
ostream& operator<<(ostream& out, const vector<A>& a) {
  out << "[";
  for (auto it = a.begin(); it != a.end(); ++it) {
    if (it != a.begin()) out << ", ";
    out << *it;
  }
  return out << "]";
}
const int INF = 1e9;
const long long INF64 = 1e18;
const int MOD = 1e9 + 7;
const long double PI = acosl(-1.0);
const long double EPS = 1e-9;
mt19937 rnd(time(NULL));
mt19937_64 rnd64(time(NULL));
const int N = 200 * 1000 + 11;
const int LOGN = 18;
int n, q;
int h[N];
vector<int> g[N];
bool read() {
  if (scanf("%d %d", &n, &q) != 2) return false;
  for (int i = 0; i < int(n - 1); ++i) {
    int p;
    scanf("%d", &p);
    --p;
    g[i + 1].push_back(p);
    g[p].push_back(i + 1);
  }
  return true;
}
int fst[N];
vector<int> ord;
void dfs(int v, int p = -1, int ch = 0) {
  h[v] = ch;
  fst[v] = int((ord).size());
  ord.push_back(v);
  for (auto to : g[v]) {
    if (to == p) continue;
    dfs(to, v, ch + 1);
    ord.push_back(v);
  }
}
pair<int, int> lcat[LOGN][N];
pair<int, int> lcas[LOGN][N];
int pw2[N];
pair<int, int> getlcat(int u, int v) {
  int l = fst[u];
  int r = fst[v];
  if (l > r) swap(l, r);
  ++r;
  int pw = pw2[r - l];
  return min(lcat[pw][l], lcat[pw][r - (1 << pw)]);
}
pair<int, int> getlcas(int l, int r) {
  ++r;
  int pw = pw2[r - l];
  return getlcat(lcas[pw][l].second, lcas[pw][r - (1 << pw)].second);
}
void build() {
  for (int i = int(2); i < int(N); ++i) pw2[i] = pw2[i / 2] + 1;
  for (int i = 0; i < int(int((ord).size())); ++i)
    lcat[0][i] = pair<int, int>(h[ord[i]], ord[i]);
  for (int i = int(1); i < int(LOGN); ++i)
    for (int j = 0; j < int(int((ord).size())); ++j) {
      lcat[i][j] =
          min(lcat[i - 1][j],
              lcat[i - 1][min(int((ord).size()) - 1, j + (1 << (i - 1)))]);
    }
  for (int i = 0; i < int(n); ++i) lcas[0][i] = pair<int, int>(h[i], i);
  for (int i = int(1); i < int(LOGN); ++i)
    for (int j = 0; j < int(n); ++j) {
      lcas[i][j] = getlcat(lcas[i - 1][j].second,
                           lcas[i - 1][min(n - 1, j + (1 << (i - 1)))].second);
    }
}
int getwho(int l, int r, int needh) {
  if (getlcas(l, r).first >= needh) {
    return -1;
  }
  if (getlcas(l + 1, r).first >= needh) {
    return l;
  }
  int lf = l, rg = r;
  while (rg - lf > 1) {
    int mid = (lf + rg) >> 1;
    if (getlcas(l, mid).first >= needh) {
      lf = mid;
    } else {
      rg = mid;
    }
  }
  if (getlcas(l, lf).first >= needh) return rg;
  return lf;
}
bool check(int l, int r, int mid) {
  int who = getwho(l, r, mid);
  if (who == -1) return true;
  pair<int, int> lca = pair<int, int>(-1, -1);
  if (who == l) {
    lca = getlcas(l + 1, r);
  } else if (who == r) {
    lca = getlcas(l, r - 1);
  } else {
    lca = getlcat(getlcas(l, who - 1).second, getlcas(who + 1, r).second);
  }
  return lca.first >= mid;
}
int geth(int l, int r) {
  int lf = 0, rg = n;
  while (rg - lf > 1) {
    int mid = (rg + lf) >> 1;
    if (check(l, r, mid))
      lf = mid;
    else
      rg = mid;
  }
  if (check(l, r, rg)) return rg;
  return lf;
}
void solve() {
  dfs(0);
  build();
  for (int _ = 0; _ < int(q); ++_) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l, --r;
    int lcah = geth(l, r);
    int who = getwho(l, r, lcah);
    if (who == -1) who = l;
    printf("%d %d\n", who + 1, lcah);
  }
}
int main() {
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  if (read()) {
    solve();
  }
}
