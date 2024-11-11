#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T, typename T1>
T maxs(T& a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T mins(T& a, T1 b) {
  if (b < a) a = b;
  return a;
}
const long long maxn = 2000005;
long long p[maxn];
long long sz[maxn];
bool s1[maxn];
bool s2[maxn];
void clear(long long n = maxn) {
  for (long long i = 0; i < maxn; i++) p[i] = i, sz[i] = 1;
}
long long root(long long first) {
  while (first != p[first]) {
    p[first] = p[p[first]];
    first = p[first];
  }
  return first;
}
void merge(long long first, long long second) {
  long long p1 = root(first);
  long long p2 = root(second);
  if (p1 == p2) return;
  if (s1[p1] && s2[p1])
    p[p2] = p1;
  else if (s1[p2] && s2[p2])
    p[p1] = p2;
  else if (s1[p1] || s2[p1])
    p[p2] = p1;
  else
    p[p1] = p2;
}
long long solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> g[n + 1];
  vector<pair<long long, long long> > edges;
  vector<pair<long long, long long> > st;
  for (long long i = 1; i < m + 1; i++) {
    long long a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
    edges.emplace_back(a, b);
  }
  long long s, t, ds, dt;
  cin >> s >> t >> ds >> dt;
  for (auto j : g[s]) {
    s1[j] = 1;
  }
  for (auto j : g[t]) {
    s2[j] = 1;
  }
  for (auto j : edges) {
    if (j.first == s || j.first == t || j.second == s || j.second == t)
      continue;
    if (root(j.first) == root(j.second)) continue;
    merge(j.first, j.second);
    st.emplace_back(j.first, j.second);
  }
  long long cnts = 0, cntt = 0, cntst = 0;
  set<long long> sts;
  vector<long long> ss(n + 1, 0), tt(n + 1, 0);
  for (long long i = 1; i < n + 1; i++) {
    if (i == s || i == t) continue;
    long long p = root(i);
    if (s1[i]) ss[p] = i;
    if (s2[i]) tt[p] = i;
    sts.insert(p);
  }
  for (auto i : sts) {
    if (ss[i] && tt[i])
      cntst++;
    else if (ss[i])
      cnts++;
    else
      cntt++;
  }
  if (cnts > ds || cntt > dt || cntst + cntt + cnts > ds + dt) {
    cout << "No"
         << "\n";
    return 0;
  }
  if (cntst == 0 && (cnts + 1 > ds || cntt + 1 > dt)) {
    cout << "No"
         << "\n";
    return 0;
  }
  if (cntst == 0) {
    st.emplace_back(s, t);
    merge(s, t);
    ds--, dt--;
  }
  for (auto i : sts) {
    if (ss[i] && tt[i] == 0)
      st.emplace_back(s, ss[i]), ds--, merge(s, ss[i]);
    else if (tt[i] && ss[i] == 0)
      st.emplace_back(t, tt[i]), dt--, merge(t, tt[i]);
    else {
      if (ds >= dt)
        st.emplace_back(s, ss[i]), ds--, merge(s, ss[i]);
      else
        st.emplace_back(t, tt[i]), dt--, merge(t, tt[i]);
    }
  }
  if (root(s) != root(t)) {
    bool f = 0;
    if (ds) {
      for (auto i : g[s]) {
        if (dt == 0 && i == t) continue;
        if (root(i) != root(s)) {
          f = 1;
          st.emplace_back(s, i);
          break;
        }
      }
    }
    if (f == 0 && dt) {
      for (auto i : g[t]) {
        if (ds == 0 && i == s) continue;
        if (root(i) != root(t)) {
          f = 1;
          st.emplace_back(t, i);
          break;
        }
      }
    }
    if (f == 0) {
      cout << "No"
           << "\n";
      return 0;
    }
  }
  cout << "Yes"
       << "\n";
  for (auto i : st) cout << i << "\n";
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  clear();
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
