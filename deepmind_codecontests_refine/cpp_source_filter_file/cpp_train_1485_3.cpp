#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxint = 2147483646;
const int minint = -2147483646;
const long long maxlll = 9223372036854775805;
const long long minlll = -9223372036854775805;
const ll mody = 998244353;
void printb(bool a) {
  if (a) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
template <class T>
void printv(vector<T> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
  os << "[";
  for (int i = 0; i < v.size(); i++) {
    os << v[i];
    if (i != v.size() - 1) {
      os << ", ";
    }
  }
  os << "]";
  return os;
}
template <class T, class U>
ostream& operator<<(ostream& os, unordered_map<T, U> dt) {
  os << "{";
  for (auto i = dt.begin(); i != dt.end(); i++) {
    os << i->first << ": " << i->second;
    auto temp = i;
    temp++;
    if (temp != dt.end()) {
      os << ", ";
    }
  }
  os << "}";
  return os;
}
template <class T, class U>
ostream& operator<<(ostream& os, pair<T, U> dt) {
  os << "(" << dt.first << "," << dt.second << ")";
  return os;
}
template <typename T, unsigned int N>
typename std::enable_if<!std::is_same<T, char>::value, std::ostream&>::type
operator<<(std::ostream& os, const T (&a)[N]) {
  for (size_t i = 0; i < N; ++i) {
    os << a[i];
    if (i < N - 1) {
      cout << " ";
    }
  }
  os << endl;
  return os;
}
template <class T, class U>
ostream& operator<<(ostream& os, map<T, U> dt) {
  os << "{";
  for (auto i = dt.begin(); i != dt.end(); i++) {
    os << i->first << ": " << i->second;
    auto temp = i;
    temp++;
    if (temp != dt.end()) {
      os << ", ";
    }
  }
  os << "}";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, set<T> dt) {
  os << "{";
  for (auto i = dt.begin(); i != dt.end(); i++) {
    os << *i;
    auto temp = i;
    temp++;
    if (temp != dt.end()) {
      os << ", ";
    }
  }
  os << "}";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, multiset<T> dt) {
  os << "{";
  for (auto i = dt.begin(); i != dt.end(); i++) {
    os << *i;
    auto temp = i;
    temp++;
    if (temp != dt.end()) {
      os << ", ";
    }
  }
  os << "}";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, stack<T> dt) {
  stack<T> t;
  os << "[";
  while (!dt.empty()) {
    T temp = dt.top();
    dt.pop();
    t.push(temp);
  }
  while (!t.empty()) {
    T temp = t.top();
    os << temp;
    t.pop();
    if (!t.empty()) {
      os << ", ";
    }
  }
  os << ")";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, queue<T> dt) {
  os << "(";
  while (!dt.empty()) {
    T temp = dt.front();
    os << temp;
    dt.pop();
    if (!dt.empty()) {
      os << ", ";
    }
  }
  os << "]";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, list<T> dt) {
  os << "[";
  for (auto i = dt.begin(); i != dt.end(); i++) {
    os << *i;
    auto temp = i;
    temp++;
    if (temp != dt.end()) {
      os << ", ";
    }
  }
  os << "]";
  return os;
}
template <class T = ll>
vector<T> clist(int n) {
  std::vector<T> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  return v;
}
template <class T = ll, class U = ll>
pair<T, U> cpair() {
  pair<T, U> p;
  cin >> p.first;
  cin >> p.second;
  return p;
}
template <class T = ll, class U = ll>
vector<pair<T, U>> clist2(int n) {
  std::vector<pair<T, U>> v(n);
  for (int i = 0; i < n; i++) {
    pair<T, U> p;
    cin >> p.first;
    cin >> p.second;
    v[i] = p;
  }
  return v;
}
template <class T = ll>
vector<pair<T, int>> clistind(int n) {
  std::vector<pair<T, int>> v(n);
  for (int i = 0; i < n; i++) {
    T k;
    cin >> k;
    pair<T, int> p(k, i);
    v[i] = p;
  }
  return v;
}
template <class T = ll, class U = ll>
vector<pair<pair<T, U>, int>> clist2ind(int n) {
  std::vector<pair<pair<T, U>, int>> v(n);
  for (int i = 0; i < n; i++) {
    pair<T, U> p;
    cin >> p.first;
    cin >> p.second;
    pair<pair<T, U>, int> pp(p, i);
    v[i] = pp;
  }
  return v;
}
vector<char> cstrtv(string& s) {
  vector<char> v;
  for (int i = 0; i < s.size(); i++) {
    v.push_back(s[i]);
  }
  return v;
}
template <class T>
struct freq {
  map<T, vector<int>> m;
  int n;
  freq(vector<T>& s) {
    n = s.size();
    for (int i = 0; i < s.size(); i++) {
      if (m.find(s[i]) == m.end()) {
        vector<int> v;
        m[s[i]] = v;
      }
      m[s[i]].push_back(i);
    }
  }
  freq(string& s) {
    n = s.size();
    for (int i = 0; i < s.size(); i++) {
      if (m.find(s[i]) == m.end()) {
        vector<int> v;
        m[s[i]] = v;
      }
      m[s[i]].push_back(i);
    }
  }
  typename map<T, vector<int>>::iterator begin() { return m.begin(); }
  typename map<T, vector<int>>::iterator end() { return m.end(); }
  int operator[](T ind) {
    if (m.find(ind) == m.end()) {
      return 0;
    }
    return m[ind].size();
  }
  T model() {
    int maxfrq = 0;
    T maxel;
    for (auto it = m.begin(); it != m.end(); it++) {
      if (it->second.size() > maxfrq) {
        maxfrq = it->second.size();
        maxel = it->first;
      }
    }
    return maxel;
  }
  int mode() { return m[model()].size(); }
  int first(T el) {
    if (m[el].size() != 0) {
      return m[el][0];
    }
    return n;
  }
  int last(T el) {
    if (m[el].size() != 0) {
      return m[el][m[el].size() - 1];
    }
    return -1;
  }
  bool equals(freq<T>& o) {
    for (auto it = begin(); it != end(); it++) {
      if ((*this)[it->first] != o[it->first]) {
        return false;
      }
    }
    for (auto it = o.begin(); it != o.end(); it++) {
      if ((*this)[it->first] != o[it->first]) {
        return false;
      }
    }
    return true;
  }
};
template <class T>
int maxind(vector<T>& v) {
  int maxi = 0;
  for (int i = 1; i < v.size(); i++) {
    maxi = (v[maxi] < v[i]) ? i : maxi;
  }
  return maxi;
}
template <class T>
T maxel(vector<T>& v) {
  return v[maxind(v)];
}
template <class T>
int minind(vector<T>& v) {
  int mini = 0;
  for (int i = 1; i < v.size(); i++) {
    mini = (v[mini] > v[i]) ? i : mini;
  }
  return mini;
}
template <class T>
T minel(vector<T>& v) {
  return v[minind(v)];
}
template <class T>
vector<ll> partialsums(vector<T>& v) {
  vector<ll> ps(v.size());
  ps[0] = v[0];
  for (int i = 1; i < v.size(); i++) {
    ps[i] = ps[i - 1] + v[i];
  }
  return ps;
}
template <class T>
ll sumy(vector<T>& v) {
  ll s = 0;
  for (int i = 0; i < v.size(); i++) {
    s += v[i];
  }
  return s;
}
template <class T>
vector<int> pminin(vector<T>& v) {
  vector<int> ret = {0};
  int curi = 0;
  for (int i = 1; i < v.size(); i++) {
    if (v[i] < v[curi]) {
      curi = i;
    }
    ret.push_back(curi);
  }
  return ret;
}
template <class T>
vector<int> pmaxin(vector<T>& v) {
  vector<int> ret = {0};
  int curi = 0;
  for (int i = 1; i < v.size(); i++) {
    if (v[i] > v[curi]) {
      curi = i;
    }
    ret.push_back(curi);
  }
  return ret;
}
template <class T>
vector<T> pmin(vector<T>& v) {
  vector<T> ret;
  vector<int> temp = pminin(v);
  for (int i = 0; i < temp.size(); i++) {
    ret.push_back(v[temp[i]]);
  }
  return ret;
}
template <class T>
vector<T> pmax(vector<T>& v) {
  vector<T> ret;
  vector<int> temp = pmaxin(v);
  for (int i = 0; i < temp.size(); i++) {
    ret.push_back(v[temp[i]]);
  }
  return ret;
}
int ind(int i, int n) {
  if (i % n >= 0) {
    return i % n;
  }
  return (i % n) + n;
}
ll modsub(ll a, ll b) {
  ll ans = a % mody - b % mody;
  if (ans < 0) {
    return ans + mody;
  }
  return ans;
}
ll gcdExtended(ll a, ll b, ll* x, ll* y);
ll modinv(ll a) {
  ll m = mody;
  ll x, y;
  ll g = gcdExtended(a, m, &x, &y);
  ll res = (x % m + m) % m;
  return res;
}
ll gcdExtended(ll a, ll b, ll* x, ll* y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  ll x1, y1;
  ll gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
ll moddiv(ll x, ll y) {
  ll dy = (modinv(y)) % mody;
  return ((x * dy) % mody);
}
template <class T = ll>
set<T> divisors(T n) {
  set<T> s;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i) {
        s.insert(i);
      } else {
        s.insert(i);
        s.insert(n / i);
      }
    }
  }
  return s;
}
template <class T = ll>
freq<T> pf(T n) {
  vector<T> s;
  while (n % 2 == 0) {
    s.push_back(2);
    n = n / 2;
  }
  for (T i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      s.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) {
    s.push_back(n);
  }
  return freq<T>(s);
}
bool isprime[1];
void seive(int n) {
  for (int i = 0; i < n + 1; i++) {
    isprime[i] = true;
    ;
  }
  isprime[0] = false;
  isprime[1] = false;
  for (int i = 0; i < n + 1; i++) {
    if (isprime[i]) {
      for (int j = 2 * i; j < n + 1; j += i) {
        isprime[j] = false;
      }
    }
  }
}
ll modexp(ll n, ll e) {
  if (e == 0) {
    return 1;
  } else {
    if (e % 2) {
      return (n * (modexp(n, e - 1))) % mody;
    } else {
      ll res = modexp(n, e / 2);
      return (res * res) % mody;
    }
  }
}
int countbits(ll n) {
  ll count = 0;
  while (n) {
    count += n & 1;
    n >>= 1;
  }
  return count;
}
string bts(ll n, int p) {
  string s = "";
  for (int i = 0; i < p; i++) {
    s.push_back('0');
  }
  for (int i = 0; i < p; i++) {
    if (n % 2) {
      s[p - i - 1] = '1';
    }
    n /= 2;
  }
  return s;
}
ll stb(string& s) {
  ll ct = 1;
  ll ret = 0;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == '1') {
      ret += ct;
    }
    ct <<= 1;
  }
  return ret;
}
int flolog(ll n) {
  int ret = 0;
  ll ini = 1;
  while ((ini << 1) <= n) {
    ini <<= 1;
    ret++;
  }
  return ret;
}
int ceilog(ll n) { return flolog(n) + ((n & (n - 1)) != 0); }
void binarysearch() {}
ll comb[1][1];
ll choose(int n, int r) {
  if (comb[n][r] != -1) {
    return comb[n][r];
  }
  if (r == n) {
    return 1;
  }
  if (r == 0) {
    return 1;
  }
  comb[n][r] = (choose(n - 1, r - 1) + choose(n - 1, r)) % (mody);
  return comb[n][r];
}
ll factorial[1];
void fillfact(int n) {
  factorial[0] = 1;
  for (int i = 1; i < n; i++) {
    factorial[i] = (factorial[i - 1] * i) % mody;
  }
}
ll chuse(ll n, ll r) {
  ll num = factorial[n];
  ll denom = (factorial[r] * factorial[n - r]) % mody;
  return moddiv(num, denom);
}
vector<vector<int>> permcyc(vector<ll>& v) {
  vector<vector<int>> cycles;
  vector<bool> done(v.size(), 0);
  for (int i = 0; i < v.size(); i++) {
    if (done[i] == 0) {
      vector<int> nc;
      done[i] = 1;
      nc.push_back(i);
      int nx = v[i];
      while (done[nx] == 0) {
        nc.push_back(nx);
        done[nx] = 1;
        nx = v[nx];
      }
      cycles.push_back(nc);
    }
  }
  return cycles;
}
struct point {
  ll a;
  ll b;
  ll c;
  point(ll aa, ll bb, ll cc) : a(aa), b(bb), c(cc) {}
  point() : a(0), b(0), c(0) {}
};
ostream& operator<<(ostream& os, point p) {
  os << "(" << p.a << ", " << p.b << ", " << p.c << ")";
  return os;
}
bool operator<(const point& a, const point& b) {
  if (a.a == b.a) {
    if (a.b == b.b) {
      return a.c < b.c;
    }
    return a.b < b.b;
  }
  return a.a < b.a;
}
point cpoint() {
  point p;
  cin >> p.a;
  cin >> p.b;
  cin >> p.c;
  return p;
}
vector<point> clist3(int n) {
  std::vector<point> v(n);
  for (int i = 0; i < n; i++) {
    point p;
    cin >> p.a;
    cin >> p.b;
    cin >> p.c;
    v[i] = p;
  }
  return v;
}
vector<pair<point, int>> clist3ind(int n) {
  std::vector<pair<point, int>> v(n);
  for (int i = 0; i < n; i++) {
    point p;
    cin >> p.a;
    cin >> p.b;
    cin >> p.c;
    pair<point, int> pp(p, i);
    v[i] = pp;
  }
  return v;
}
template <class T>
vector<int> islets(vector<T>& v) {
  vector<int> ret;
  int cur = 1;
  for (int i = 1; i < v.size(); i++) {
    if (v[i] == v[i - 1]) {
      cur++;
    } else {
      ret.push_back(cur);
      cur = 1;
    }
  }
  ret.push_back(cur);
  return ret;
}
template <class T>
vector<int> islets2(vector<T>& v, T el) {
  vector<int> ret;
  int cur = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == el) {
      cur++;
    } else {
      if (cur != 0) {
        ret.push_back(cur);
        cur = 0;
      }
    }
  }
  if (cur != 0) {
    ret.push_back(cur);
  }
  return ret;
}
struct node;
struct edge;
struct node {
  int pos;
  int tag = 0;
  vector<edge> edges;
  node(int valy) : pos(valy) {}
  node(int valy, int taggy) : pos(valy), tag(taggy) {}
  void add(edge& e) { edges.push_back(e); }
};
struct edge {
  node* source;
  node* dest;
  int weight = 0;
  edge(node* sourcey, node* desty) : source(sourcey), dest(desty) {}
  edge(node* sourcey, node* desty, int valy)
      : source(sourcey), dest(desty), weight(valy) {}
};
struct graph {
  vector<node> nodes;
  bool d;
  graph(int sz, int dd = 0) {
    d = dd;
    for (int i = 0; i < sz; i++) {
      node v(i);
      nodes.push_back(v);
    }
  }
  void addnode(int taggy = 0) {
    node v(nodes.size(), taggy);
    nodes.push_back(v);
  }
  void addedge(int source, int dest, int weight = 0) {
    node& so = nodes[source];
    node& de = nodes[dest];
    edge e(&so, &de, weight);
    nodes[source].add(e);
    if (d == 0) {
      edge ee(&de, &so, weight);
      nodes[dest].add(ee);
    }
  }
  void cgraph(int n) {
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      addedge(a, b);
    }
  }
  vector<int> dfs() {
    vector<int> parent(nodes.size(), -1);
    for (int i = 0; i < nodes.size(); i++) {
      if (parent[i] == -1) {
        stack<int> s;
        s.push(i);
        parent[i] = i;
        while (!s.empty()) {
          int cur = s.top();
          s.pop();
          for (int i = 0; i < nodes[cur].edges.size(); i++) {
            if (parent[nodes[cur].edges[i].dest->pos] == -1) {
              s.push(nodes[cur].edges[i].dest->pos);
              parent[nodes[cur].edges[i].dest->pos] = cur;
            }
          }
        }
      }
    }
    return parent;
  }
  vector<int> dfscomp() {
    vector<int> parent(nodes.size(), -1);
    for (int i = 0; i < nodes.size(); i++) {
      if (parent[i] == -1) {
        stack<int> s;
        s.push(i);
        parent[i] = i;
        int pa = i;
        while (!s.empty()) {
          int cur = s.top();
          s.pop();
          for (int i = 0; i < nodes[cur].edges.size(); i++) {
            if (parent[nodes[cur].edges[i].dest->pos] == -1) {
              s.push(nodes[cur].edges[i].dest->pos);
              parent[nodes[cur].edges[i].dest->pos] = pa;
            }
          }
        }
      }
    }
    return parent;
  }
  vector<int> bfs(int sp) {
    vector<int> parent(nodes.size(), -1);
    vector<int> dist(nodes.size(), 0);
    int i = sp;
    queue<int> s;
    s.push(i);
    parent[i] = -1;
    while (!s.empty()) {
      int cur = s.front();
      s.pop();
      if (cur == sp) {
        dist[cur] = 0;
      } else {
        dist[cur] = dist[parent[cur]] + 1;
      }
      for (int i = 0; i < nodes[cur].edges.size(); i++) {
        if (parent[nodes[cur].edges[i].dest->pos] == -1) {
          s.push(nodes[cur].edges[i].dest->pos);
          parent[nodes[cur].edges[i].dest->pos] = cur;
        }
      }
    }
    return dist;
  }
  set<int> leafs() {
    set<int> leafs;
    vector<int> parent(nodes.size(), -1);
    for (int i = 0; i < nodes.size(); i++) {
      if (parent[i] == -1) {
        stack<int> s;
        s.push(i);
        parent[i] = i;
        while (!s.empty()) {
          int cur = s.top();
          if (nodes[cur].edges.size() == 1) {
            leafs.insert(cur);
          }
          s.pop();
          for (int i = 0; i < nodes[cur].edges.size(); i++) {
            if (parent[nodes[cur].edges[i].dest->pos] == -1) {
              s.push(nodes[cur].edges[i].dest->pos);
              parent[nodes[cur].edges[i].dest->pos] = cur;
            }
          }
        }
      }
    }
    return leafs;
  }
  vector<int> treesizes(int root) {
    vector<int> sizes(nodes.size(), 1);
    ftreesizes(root, -1, sizes);
    return sizes;
  }
  void ftreesizes(int val, int par, vector<int>& s) {
    for (int i = 0; i < nodes[val].edges.size(); i++) {
      if (nodes[val].edges[i].dest->pos != par) {
        ftreesizes(nodes[val].edges[i].dest->pos, val, s);
        s[val] += s[nodes[val].edges[i].dest->pos];
      }
    }
  }
};
ostream& operator<<(ostream& os, graph g) {
  os << "{";
  for (int i = 0; i < g.nodes.size(); i++) {
    os << g.nodes[i].pos << ":[";
    for (int j = 0; j < g.nodes[i].edges.size(); j++) {
      os << g.nodes[i].edges[j].dest->pos << "(" << g.nodes[i].edges[j].weight
         << "), ";
    }
    os << "]" << endl;
  }
  os << "}";
  return os;
}
map<ll, vector<int>> intervalin(int n) {
  map<ll, vector<int>> m;
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    m[a].push_back(-i - 1);
    m[b].push_back(i + 1);
  }
  for (auto it = m.begin(); it != m.end(); it++) {
    sort(it->second.begin(), it->second.end());
  }
  return m;
}
template <class T = ll>
struct matrix {
  vector<vector<T>> v;
  int r, c;
  matrix(int ar, int ac, int sig = -1) : r(ar), c(ac) {
    if (sig != -1) {
      for (int i = 0; i < r; i++) {
        vector<T> vv(c, 0);
        v.push_back(vv);
      }
    }
    if (sig == 1) {
      for (int i = 0; i < r; i++) {
        v[i][i] = 1;
      }
    }
  }
  void cmatrix() {
    for (int i = 0; i < r; i++) {
      vector<T> vv = clist<T>(c);
      v.push_back(vv);
    }
  }
  void csmatrix() {
    for (int i = 0; i < r; i++) {
      string ss;
      cin >> ss;
      v.push_back(cstrtv(ss));
    }
  }
  vector<T> row(int i) { return v[i]; }
  vector<T> col(int i) {
    vector<T> f(r);
    for (int j = 0; j < r; j++) {
      f[j] = (v[j][i]);
    }
    return f;
  }
  vector<T> splay(bool dag = 0) {
    vector<T> ret(r * c);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        int jy = (i % 2 && dag) ? (c - j - 1) : j;
        ret[i * c + j] = v[i][jy];
      }
    }
    return ret;
  }
  freq<T> count() {
    vector<T> inter = splay();
    return freq<T>(inter);
  }
  vector<T>& operator[](int ind) { return v[ind]; }
  vector<T> operator()(int ind) { return col(ind); }
  matrix<ll> modmult(matrix<ll> mp) {
    matrix mult(r, mp.c, 0);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < mp.c; j++) {
        for (int k = 0; k < c; k++) {
          mult[i][j] += (v[i][k] * mp[k][j]) % mody;
          mult[i][j] %= mody;
        }
      }
    }
    return mult;
  }
  matrix<ll> modexp(ll e) {
    if (e == 0) {
      return matrix(r, r, 1);
    } else {
      if (e % 2) {
        return modmult(modexp(e - 1));
      } else {
        auto mint = modexp(e / 2);
        return mint.modmult(mint);
      }
    }
  }
};
template <class T>
ostream& operator<<(ostream& os, matrix<T> p) {
  for (int i = 0; i < p.r; i++) {
    cout << p[i] << endl;
  }
  return os;
}
struct cj {
  static void print(int i) { cout << "Case #" << i + 1 << ": "; }
};
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  int t;
  t = 1;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> weights;
    queue<int> q;
    vector<int> pr;
    vector<vector<int>> v(n);
    vector<int> vv(n);
    map<pair<int, int>, queue<int>> edgy;
    vector<int> done(n);
    vector<int> cont(n);
    for (int i = 0; i < n; i++) {
      int f;
      cin >> f;
      weights.push_back(f);
    }
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      v[x].push_back(y);
      v[y].push_back(x);
      vv[x]++;
      vv[y]++;
      pair<int, int> p(min(x, y), max(y, x));
      edgy[p].push(i);
    }
    for (int i = 0; i < n; i++) {
      if (v[i].size() <= weights[i]) {
        q.push(i);
        done[i] = true;
        ;
      }
    }
    while (!q.empty()) {
      int no = q.front();
      q.pop();
      for (int i = 0; i < v[no].size(); i++) {
        int el = v[no][i];
        if (done[el]) {
          continue;
        }
        vv[el]--;
        pr.push_back(edgy[{min(no, el), max(no, el)}].front());
        edgy[{min(no, el), max(no, el)}].pop();
        if (weights[el] >= vv[el] && cont[el] == 0) {
          q.push(el);
          cont[el] = 1;
        }
      }
      done[no] = true;
    }
    if (pr.size() != m) {
      cout << "DEAD" << endl;
    } else {
      cout << "ALIVE" << endl;
      reverse(pr.begin(), pr.end());
      for (int i = 0; i < pr.size(); i++) {
        cout << pr[i] + 1 << " ";
      }
    }
  }
}
