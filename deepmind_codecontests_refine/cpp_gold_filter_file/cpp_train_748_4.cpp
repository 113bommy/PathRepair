#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
void pre() {}
void solve() {}
int p[100];
int vis[109];
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  pre();
  int n;
  cin >> n;
  for (int i = 0; i < (n); ++i) {
    cin >> p[i];
    vis[p[i]] = 1;
  }
  vector<pair<int, int> > v;
  for (int i = 0; i < (n); ++i)
    if (p[i]) p[i] = p[i] % 2 + 2;
  v.push_back(make_pair(p[0], 1));
  for (int i = 1; i <= (n - 1); ++i) {
    if (p[i] == p[i - 1])
      v.back().second++;
    else
      v.push_back(make_pair(p[i], 1));
  }
  if ((int)(v).size() == 1) {
    if (p[0] == 0) {
      if (n == 1)
        cout << 0;
      else
        cout << 1;
    } else
      cout << 0;
    return 0;
  }
  vector<int> cnt[2];
  int fns = 0;
  for (int i = 0; i < ((int)(v).size()); ++i) {
    if (v[i].first == 0) {
      if (i == 0)
        ;
      else if (i == (int)(v).size() - 1)
        ;
      else if (v[i - 1].first % 2 == v[i + 1].first % 2)
        cnt[v[i - 1].first % 2].push_back(v[i].second);
      else
        fns++;
    } else if (i != (int)(v).size() - 1 && v[i + 1].first != 0 &&
               v[i].first != v[i + 1].first) {
      fns++;
    }
  }
  int val[2];
  val[0] = val[1] = 0;
  for (int i = 1; i <= (n); ++i)
    if (!vis[i]) val[i % 2]++;
  sort(cnt[0].begin(), cnt[0].end());
  sort(cnt[1].begin(), cnt[1].end());
  reverse(cnt[0].begin(), cnt[0].end());
  reverse(cnt[1].begin(), cnt[1].end());
  int gns = n;
  int st[2];
  st[0] = val[0], st[1] = val[1];
  vector<int> gg1 = cnt[0], gg2 = cnt[1];
  int cns = fns;
  for (int q = 0; q < (4); ++q) {
    val[0] = st[0];
    val[1] = st[1];
    cnt[0] = gg1;
    cnt[1] = gg2;
    fns = cns;
    if (v[(int)(v).size() - 1].first == 0) {
      if (q & 2) {
        if (val[v[(int)(v).size() - 2].first % 2] >=
            v[(int)(v).size() - 1].second) {
          val[v[(int)(v).size() - 2].first % 2] -=
              v[(int)(v).size() - 1].second;
        } else
          fns++;
      } else
        fns++;
    }
    if (v[0].first == 0) {
      if (q & 1) {
        if (val[v[1].first % 2] >= v[0].second) {
          val[v[1].first % 2] -= v[0].second;
        } else
          fns++;
      } else
        fns++;
    }
    while ((int)(cnt[1]).size() && cnt[1].back() <= val[1]) {
      val[1] -= cnt[1].back();
      cnt[1].pop_back();
    }
    while ((int)(cnt[0]).size() && cnt[0].back() <= val[0]) {
      val[0] -= cnt[0].back();
      cnt[0].pop_back();
    }
    gns = min(gns, fns + 2 * ((int)(cnt[0]).size() + (int)(cnt[1]).size()));
  }
  cout << gns;
  return 0;
}
