#include <bits/stdc++.h>
using namespace std;
template <class T>
using vv = vector<vector<T>>;
template <class T>
ostream &operator<<(ostream &os, const vector<T> &t) {
  os << "{";
  for (int(i) = 0; (i) < (t.size()); ++(i)) {
    os << t[i] << ",";
  }
  os << "}" << endl;
  return os;
}
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &t) {
  return os << "(" << t.first << "," << t.second << ")";
}
template <class T>
inline bool MX(T &l, const T &r) {
  return l < r ? l = r, 1 : 0;
}
template <class T>
inline bool MN(T &l, const T &r) {
  return l > r ? l = r, 1 : 0;
}
vector<string> s_p_l_i_t(const string &s, char c) {
  vector<string> v;
  int d = 0, f = 0;
  string t;
  for (char c : s) {
    if (!d && c == ',')
      v.push_back(t), t = "";
    else
      t += c;
    if (c == '\"' || c == '\'') f ^= 1;
    if (!f && c == '(') ++d;
    if (!f && c == ')') --d;
  }
  v.push_back(t);
  return move(v);
}
void e_r_r(vector<string>::iterator it) {}
template <typename T, typename... Args>
void e_r_r(vector<string>::iterator it, T a, Args... args) {
  if (*it == " 1" || *it == "1")
    cerr << endl;
  else
    cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << ", ";
  e_r_r(++it, args...);
}
const long long MOD = 1e9 + 7;
const int MAX_P = 1123456;
int prime[MAX_P];
void Fact(int n, map<long long, long long> &re) {
  while (prime[n]) {
    ++re[prime[n]];
    n /= prime[n];
  }
  if (n > 1) ++re[n];
}
void pre() {
  int i, j, k;
  for (i = 2; i < MAX_P; i++) {
    if (prime[i] == 0)
      for (long long j = 1ll * i * i; j < MAX_P; j += i) prime[j] = i;
  }
}
map<pair<pair<long long, long long>, long long>, long long> memo;
long long dfs(vector<pair<long long, long long>> &ps, int i, long long x) {
  if (ps.size() == i) return x >= 0;
  long long re = dfs(ps, i + 1, x);
  for (int(_) = 0; (_) < (ps[i].second); ++(_)) {
    x /= ps[i].first;
    if (!x) break;
    re += dfs(ps, i + 1, x);
  }
  return re;
}
long long dfs2(vector<pair<long long, long long>> &ps, int i, long long x) {
  if (ps.size() == i) {
    if (!x) return 0;
    long long re = 0;
    int n = ps.size();
    for (int(i) = 0; (i) < (1 << n); ++(i)) {
      long long t = x;
      for (int(j) = 0; (j) < (n); ++(j))
        if (i >> j & 1) t /= ps[j].first;
      re += (__builtin_popcount(i) % 2 ? -t : t);
    }
    return re;
  }
  long long re = dfs2(ps, i + 1, x);
  for (int(_) = 0; (_) < (ps[i].second); ++(_)) {
    x /= ps[i].first;
    if (!x) break;
    re += dfs2(ps, i + 1, x);
  }
  return re;
}
int main() {
  pre();
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(0);
  int T;
  cin >> T;
  while (T--) {
    map<long long, long long> xs, ys, ss;
    long long first = 1, second = 1, S = 1;
    for (int(i) = 0; (i) < (3); ++(i)) {
      long long t;
      cin >> t;
      first *= t;
      Fact(t, xs);
    }
    for (int(i) = 0; (i) < (3); ++(i)) {
      long long t;
      cin >> t;
      second *= t;
      Fact(t, ys);
    }
    for (int(i) = 0; (i) < (3); ++(i)) {
      long long t;
      cin >> t;
      S *= t;
      Fact(t, ss);
    }
    S *= 2;
    ++ss[2];
    if (memo.count(make_pair(pair<long long, long long>(first, second), S))) {
      cout << memo[make_pair(pair<long long, long long>(first, second), S)]
           << endl;
    }
    long long &re =
        memo[make_pair(pair<long long, long long>(first, second), S)];
    vector<pair<long long, long long>> ps((ss).begin(), (ss).end());
    reverse((ps).begin(), (ps).end());
    re += dfs(ps, 0, first);
    map<long long, long long> ts;
    for (pair<long long, long long> p : xs) {
      if (ss[p.first] < p.second) ts[p.first] = ss[p.first];
    }
    vector<pair<long long, long long>> tv((ts).begin(), (ts).end());
    re += dfs2(tv, 0, second);
    cout << re << endl;
  }
  return 0;
}
