#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline string tostr(const T& x) {
  stringstream ss;
  ss << x;
  return ss.str();
}
inline long long parse(const string& s) {
  stringstream ss(s);
  long long x;
  ss >> x;
  return x;
}
const double EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;
const char CINF = 102;
const long long LINF = INF * 1ll * INF;
const double DINF = 1e200;
const double PI = 3.1415926535897932384626433832795l;
int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
long long gcd(long long a, long long b) { return a ? gcd(b % a, a) : b; }
long long powmod(long long a, long long p, long long m) {
  long long r = 1;
  while (p) {
    if (p & 1) r = r * a % m;
    p >>= 1;
    a = a * a % m;
  }
  return r;
}
vector<vector<pair<int, int> > > gr;
vector<char> was;
vector<long long> W;
pair<int, long long> dfs(int v, int e0) {
  if (was[v]) return make_pair(0, 0);
  was[v] = true;
  pair<int, long long> r(1, W[v]);
  for (int i = 0; i < (((int)(gr[v]).size())); ++i) {
    if (gr[v][i].second >= e0) continue;
    int p = gr[v][i].first;
    auto t = dfs(p, e0);
    r.first += t.first;
    r.second += t.second;
  }
  return r;
}
bool check(int e0) {
  was.assign(((int)(gr).size()), 0);
  vector<pair<int, long long> > A;
  long long s = 0;
  for (int i = 0; i < (((int)(gr).size())); ++i) {
    if (!was[i]) {
      A.push_back(dfs(i, e0));
      s += A.back().second;
    }
  }
  for (int i = 0; i < (((int)(A).size())); ++i) {
    if (A[i].first > s - A[i].second) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  gr.resize(n);
  vector<int> es;
  for (int i = 0; i < (n - 1); ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    --a;
    --b;
    gr[a].push_back(make_pair(b, c));
    gr[b].push_back(make_pair(a, c));
    es.push_back(c);
  }
  W.resize(n);
  for (int i = 0; i < (n); ++i) {
    cin >> W[i];
  }
  sort((es).begin(), (es).end());
  es.erase(unique((es).begin(), (es).end()), es.end());
  int a = 0, b = ((int)(es).size());
  while (b > a + 1) {
    int c = (a + b) / 2;
    if (check(es[c]))
      a = c;
    else
      b = c;
  }
  cout << ((int)(es).size()) ? es[a] : 0;
  return 0;
}
