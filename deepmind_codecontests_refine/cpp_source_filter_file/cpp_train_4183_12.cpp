#include <bits/stdc++.h>
using namespace std;
ifstream in;
ofstream out;
const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;
const long long gs = 500 * kk;
long n, m, i, j, s, b, k, h;
vector<long> reb[gs + 10];
vector<vector<long long>> dist;
vector<pair<long long, pair<long long, long long>>> putin;
vector<pair<long long, long long>> navalny;
vector<long long> edros;
vector<bool> was;
vector<vector<long long>> p_reb, n_reb;
vector<long long> col, tc;
bool viv = false;
void BFS(long v) {
  vector<long> st;
  st.push_back(v);
  long s = 0;
  tc[v] = 0;
  while (s < st.size()) {
    long e = st[s];
    long l = reb[e].size();
    for (long i = 0; i < l; i++) {
      long s = reb[e][i];
      if (tc[s] == -1) {
        st.push_back(s);
        tc[s] = tc[e] + 1;
      }
    }
    s++;
  }
}
void all_dist() {
  for (long long i = 0; i < n; i++) {
    tc.clear();
    tc.resize(n, -1);
    BFS(i);
    dist.push_back(tc);
  }
}
void make_edges() {
  p_reb.resize(s);
  n_reb.resize(b);
  if (viv) cout << "Let's work" << endl;
  for (long long i = 0; i < s; i++)
    for (long long j = 0; j < b; j++)
      if (putin[i].second.first >= navalny[j].second)
        if (dist[putin[i].first][navalny[j].first] <= putin[i].second.second)
          p_reb[i].push_back(j), n_reb[j].push_back(i);
  if (viv) {
    cout << "Put:" << endl;
    for (auto vec : p_reb) {
      for (auto e : vec) cout << e << ' ';
      cout << endl;
    }
    cout << "Nav:" << endl;
    for (auto vec : n_reb) {
      for (auto e : vec) cout << e << ' ';
      cout << endl;
    }
  }
}
bool kuhn(long long er) {
  if (viv) cout << "Try found for er=" << er << endl;
  if (was[er]) return false;
  was[er] = true;
  for (auto fbk : p_reb[er])
    if (edros[fbk] == -1 || kuhn(edros[fbk])) {
      edros[fbk] = er;
      if (viv) cout << "OK " << er << " on " << fbk << endl;
      return true;
    }
  return false;
}
long long max_matching() {
  make_edges();
  edros.resize(b, -1);
  was.resize(s);
  long long lans = 0;
  for (long long i = 0; i < s; i++) {
    for (j = 0; j < was.size(); j++) was[j] = false;
    if (kuhn(i)) lans++;
  }
  if (viv) {
    cout << "Answer is " << lans << endl;
    for (auto i : edros) cout << i << ' ';
    cout << endl;
  }
  return lans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    long a, b;
    cin >> a >> b;
    a--;
    b--;
    reb[a].push_back(b);
    reb[b].push_back(a);
  }
  all_dist();
  if (viv) {
    for (auto v : dist) {
      for (auto d : v) cout << d << ' ';
      cout << endl;
    }
  }
  cin >> s >> b >> k >> h;
  for (long long i = 0; i < s; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    a--;
    putin.push_back({a, {b, c}});
  }
  for (long long i = 0; i < b; i++) {
    long long a, b;
    cin >> a >> b;
    a--;
    navalny.push_back({a, b});
  }
  long long mm = max_matching();
  long long ans = inf;
  for (long long i = 0; i < s; i++) {
    long long lans = 0;
    lans += min(i, mm) * k;
    lans += (s - i) * h;
    ans = min(ans, lans);
  }
  cout << ans;
  return 0;
}
