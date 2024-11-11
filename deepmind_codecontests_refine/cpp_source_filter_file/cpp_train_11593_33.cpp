#include <bits/stdc++.h>
using namespace std;
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v);
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
template <typename A, typename B>
istream &operator>>(istream &cin, pair<A, B> &p) {
  cin >> p.first;
  return cin >> p.second;
}
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
void usaco(string filename) {
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
}
const long double pi = 3.14159265358979323846;
long long n, m, k, q, l, r, x, y, z;
const long long template_array_size = 1e6 + 6884;
long long a[template_array_size];
long long b[template_array_size];
long long c[template_array_size];
string second, t;
long long ans = 0;
struct game {
  string a, b;
  long long sa, sb;
} g[6];
bool eval() {
  map<string, pair<long long, pair<long long, long long>>> mp;
  for (long long i = 0; i < 6; i++) {
    mp[g[i].a].second.first += g[i].sa;
    mp[g[i].a].second.second += g[i].sb;
    mp[g[i].b].second.first += g[i].sb;
    mp[g[i].b].second.second += g[i].sa;
    if (g[i].sa > g[i].sb)
      mp[g[i].a].first += 3;
    else if (g[i].sa < g[i].sb)
      mp[g[i].b].first += 3;
    else {
      mp[g[i].a].first += 1;
      mp[g[i].b].first += 1;
    }
  }
  vector<pair<pair<long long, long long>, pair<long long, string>>> ord;
  for (pair<string, pair<long long, pair<long long, long long>>> x : mp) {
    ord.push_back(
        make_pair(make_pair(-x.second.first,
                            x.second.second.second - x.second.second.first),
                  make_pair(-x.second.second.first, x.first)));
  }
  sort(ord.begin(), ord.end());
  for (long long i = 0; i < 2; i++) {
    if (ord[i].second.second == "BERLAND") return 1;
  }
  return 0;
}
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first - a.second == b.first - b.second) return a.second < b.second;
  return a.first - a.second < b.first - b.second;
}
void solve(int tc = 0) {
  map<string, long long> cnt;
  for (long long i = 0; i < 5; i++) {
    char c;
    cin >> g[i].a >> g[i].b >> g[i].sa >> c >> g[i].sb;
    ++cnt[g[i].a];
    ++cnt[g[i].b];
  }
  for (pair<string, long long> x : cnt) {
    if (x.second == 2 && x.first != "BERLAND") t = x.first;
  }
  g[5].a = "BERLAND";
  g[5].b = t;
  const long long MX = 7;
  vector<pair<long long, long long>> ans;
  for (long long i = 0; i < MX; i++) {
    for (long long j = 0; j < MX; j++) {
      g[5].sa = i, g[5].sb = j;
      if (i > j && eval()) ans.push_back(make_pair(i, j));
    }
  }
  sort(ans.begin(), ans.end(), cmp);
  if (ans.size() == 0)
    cout << "IMPOSSIBLE\n";
  else
    cout << ans[0].first << ":" << ans[0].second << '\n';
}
int main() {
  { ios_base::sync_with_stdio(false); }
  { cin.tie(NULL); }
  cout << setprecision(12) << fixed;
  int tc = 1;
  for (int t = 0; t < tc; t++) solve(t);
}
