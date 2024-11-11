#include <bits/stdc++.h>
using namespace std;
void display(vector<long long> &a) {
  for (long long z : a) cout << z << " ";
  cout << endl;
}
long long dx[4] = {0, 0, 1, -1};
long long dy[4] = {1, -1, 0, 0};
const long long mod = (long long)1e9 + 7;
const long long INF64 = 3e18;
void smxl(long long &a, long long b) {
  if (a < b) a = b;
}
void smnl(long long &a, long long b) {
  if (a > b) a = b;
}
void adsl(long long &a, long long b) {
  a += b;
  if (a >= mod) a -= mod;
}
void misl(long long &a, long long b) {
  a -= b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}
void smx(long long &a, long long b) {
  if (a < b) a = b;
}
void smn(long long &a, long long b) {
  if (a > b) a = b;
}
void ads(long long &a, long long b) {
  a += b;
  if (a >= mod) a -= mod;
}
void mis(long long &a, long long b) {
  a -= b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
long long egcd(long long a, long long b, long long &x, long long &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long x1, y1;
  long long d = egcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
long long mbinp(long long a, long long b) {
  a %= mod;
  if (b == 0) return 1;
  long long ans = mbinp(a, b / 2);
  long long tmp = (ans * ans) % mod;
  if (b % 2) return ((tmp * a) % mod);
  return ((tmp) % mod);
}
long long binp(long long a, long long b) {
  if (b == 0) return 1;
  long long ans = binp(a, b / 2);
  long long tmp = (ans * ans);
  if (b % 2) return ((tmp * a));
  return ((tmp));
}
long long C(long long n, long long m) {
  long long ret = 1;
  for (long long i = 1; i <= m; i++) {
    ret *= (n - i + 1);
    ret /= i;
  }
  return ret;
}
long long overbinp(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      if (res < INF64 / a)
        res *= a;
      else
        return INF64;
    }
    if (b > 1) {
      if (a < INF64 / a)
        a *= a;
      else
        return INF64;
    }
    b >>= 1;
  }
  return res;
}
class DSU {
  vector<long long> par;
  vector<long long> siize;

 public:
  DSU(long long n) {
    par.resize(n);
    siize.resize(n);
    for (long long i = 0; i < n; i++) {
      par[i] = i;
      siize[i] = 1;
    }
  }

 public:
  long long get(long long x) {
    return (x == par[x] ? x : par[x] = get(par[x]));
  }

 public:
  void merge(long long a, long long b) {
    long long x = get(a);
    long long y = get(b);
    if (x == y) return;
    if (siize[x] < siize[y]) swap(x, y);
    par[y] = x;
    siize[x] += siize[y];
  }
};
class BinaryLift {
  vector<vector<long long> > binlift;
  long long n;

 public:
  BinaryLift(vector<long long> rnk, vector<long long> par) {
    n = (long long)par.size();
    binlift.resize(n);
    for (long long i = 0; i < n; i++) binlift[i].resize(20);
    for (long long i = 0; i < n; i++) binlift[i][0] = par[i];
    for (long long j = 1; j < 20; j++)
      for (long long i = 0; i < n; i++) {
        if ((1 << j) < rnk[i])
          binlift[i][j] = binlift[binlift[i][j - 1]][j - 1];
        else
          binlift[i][j] = -1;
      }
  }

 public:
  long long get_kth_ancestor(long long x, long long k) {
    long long pt = x;
    for (long long i = 19; i >= 0; i--) {
      if (pt == -1) exit(0);
      if (k & (1 << i)) pt = binlift[pt][i];
    }
    return pt;
  }

 public:
  long long get_th_ancestor(long long x, long long k) {
    long long pt = x;
    for (long long i = 19; i >= 0; i--) {
      if (k & (1 << i)) pt = binlift[pt][i];
    }
    return pt;
  }
};
class SparseTable2D {
  vector<vector<vector<vector<long long> > > > sparse;
  vector<vector<long long> > inp;
  long long m, n;

 private:
  long long lg2(long long x) {
    long long out = 0;
    while ((1 << out) <= x) out++;
    return out - 1;
  }

 public:
  long long rmin(long long x1, long long y1, long long x2, long long y2) {
    long long lenx = x2 - x1 + 1;
    long long lx = lg2(lenx) + 1;
    long long leny = y2 - y1 + 1;
    long long ly = lg2(leny) + 1;
    return min(
        min(sparse[lx][x1][ly][y1], sparse[lx][x1][ly][y2 + 1 - (1 << ly)]),
        min(sparse[lx][x2 + 1 - (1 << lx)][ly][y1],
            sparse[lx][x2 + 1 - (1 << lx)][ly][y2 + 1 - (1 << ly)]));
  }

 public:
  SparseTable2D(vector<vector<long long> > input, string param) {
    n = input.size();
    m = input[0].size();
    inp = input;
    if (param == "min") prepromin();
  }

 private:
  void prepromin() {
    long long lln, lm;
    lln = lg2(n) + 1;
    lm = lg2(m) + 1;
    sparse.resize(lln);
    for (long long i = 0; i < lln; i++) sparse[i].resize(n);
    for (long long i = 0; i < lln; i++)
      for (long long j = 0; j < n; j++) sparse[i][j].resize(lm);
    for (long long i = 0; i < lln; i++)
      for (long long j = 0; j < n; j++)
        for (long long k = 0; k < lm; k++) sparse[i][j][k].resize(m);
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) sparse[0][i][0][j] = inp[i][j];
      for (long long j = 1; j < lm; j++)
        for (long long k = 0; k + (1 << j) - 1 < m; k++)
          sparse[0][i][j][k] = min(sparse[0][i][j - 1][k],
                                   sparse[0][i][j - 1][k + (1 << (j - 1))]);
    }
    for (long long i = 1; i < lln; i++)
      for (long long j = 0; j + (1 << i) - 1 < n; j++)
        for (long long k = 0; k < lm; k++)
          for (long long h = 0; h < m; h++)
            sparse[i][j][k][h] = min(sparse[i - 1][j][k][h],
                                     sparse[i - 1][j + (1 << (i - 1))][k][h]);
  }
};
class SparseTable {
  vector<vector<long long> > sparse;
  long long n;
  vector<long long> input;

 private:
  long long lg2(long long x) {
    long long out = 0;
    while ((1 << out) <= x) out++;
    return out - 1;
  }

 public:
  long long rmaxpos(long long left, long long right) {
    long long len = right - left + 1;
    long long lg = lg2(len);
    return (input[sparse[left][lg]] > input[sparse[left + len - (1 << lg)][lg]]
                ? sparse[left][lg]
                : sparse[left + len - (1 << lg)][lg]);
  }

 public:
  long long rmaxval(long long left, long long right) {
    long long len = right - left + 1;
    long long lg = lg2(len);
    return (input[sparse[left][lg]] > input[sparse[left + len - (1 << lg)][lg]]
                ? input[sparse[left][lg]]
                : input[sparse[left + len - (1 << lg)][lg]]);
  }

 public:
  long long rminpos(long long left, long long right) {
    long long len = right - left + 1;
    long long lg = lg2(len);
    return (input[sparse[left][lg]] < input[sparse[left + len - (1 << lg)][lg]]
                ? sparse[left][lg]
                : sparse[left + len - (1 << lg)][lg]);
  }

 public:
  long long rminval(long long left, long long right) {
    long long len = right - left + 1;
    long long lg = lg2(len);
    return (input[sparse[left][lg]] < input[sparse[left + len - (1 << lg)][lg]]
                ? input[sparse[left][lg]]
                : input[sparse[left + len - (1 << lg)][lg]]);
  }

 public:
  long long rsum(long long left, long long right) {
    long long ans = 0;
    long long pos;
    while (left <= right) {
      for (long long i = 19; i >= 0; i--)
        if ((1 << i) <= right - left + 1) {
          pos = i;
          break;
        }
      ans += sparse[left][pos];
      left = left + (1 << pos);
    }
    return ans;
  }

 public:
  SparseTable(vector<long long> inp, string operation) {
    input = inp;
    n = inp.size();
    if (operation == "min")
      prepromin();
    else if (operation == "max")
      prepromax();
    else if (operation == "sum")
      preprosum();
  }

 private:
  void prepromin() {
    sparse.resize(n);
    long long x = lg2(n) + 1;
    for (long long i = 0; i < n; i++) sparse[i].resize(x);
    for (long long i = 0; i < n; i++) sparse[i][0] = i;
    for (long long j = 1; j < x; j++)
      for (long long i = 0; i + (1 << (j)) - 1 < n; i++)
        sparse[i][j] =
            (input[sparse[i][j - 1]] < input[sparse[i + (1 << (j - 1))][j - 1]]
                 ? sparse[i][j - 1]
                 : sparse[i + (1 << (j - 1))][j - 1]);
  }
  void prepromax() {
    sparse.resize(n);
    long long x = lg2(n) + 1;
    for (long long i = 0; i < n; i++) sparse[i].resize(x);
    for (long long i = 0; i < n; i++) sparse[i][0] = i;
    for (long long j = 1; j < x; j++)
      for (long long i = 0; i + (1 << (j)) - 1 < n; i++)
        sparse[i][j] =
            (input[sparse[i][j - 1]] > input[sparse[i + (1 << (j - 1))][j - 1]]
                 ? sparse[i][j - 1]
                 : sparse[i + (1 << (j - 1))][j - 1]);
  }
  void preprosum() {
    sparse.resize(n);
    long long x = lg2(n) + 1;
    for (long long i = 0; i < n; i++) sparse[i].resize(x);
    for (long long i = 0; i < n; i++) sparse[i][0] = input[i];
    for (long long j = 1; j < x; j++)
      for (long long i = 0; i + (1 << (j)) - 1 < n; i++)
        sparse[i][j] = sparse[i][j - 1] + sparse[i + (1 << (j - 1))][j - 1];
  }
};
class Vector {
 public:
  pair<long long, long long> x;

 public:
  Vector(pair<long long, long long> a, pair<long long, long long> b) {
    x.first = b.first - a.first;
    x.second = b.second - a.second;
  }

 public:
  long double getMagnitude() {
    return sqrtl(x.first * x.first + x.second * x.second);
  }
};
class Line {
 public:
  pair<long long, long long> x, y;

 public:
  Line(pair<long long, long long> a, pair<long long, long long> b) {
    x = a;
    y = b;
  }

 private:
  long double dotProduct(Vector a, Vector b) {
    return a.x.first * b.x.first + a.x.second * b.x.second;
  }

 private:
  long double crossProduct(Vector a, Vector b) {
    return a.x.first * b.x.second - a.x.second * b.x.first;
  }

 private:
  long double magnitude(Vector a) { return a.getMagnitude(); }

 public:
  long double distanceToA(pair<long long, long long> c) {
    return dotProduct(Vector(x, y), Vector(x, c)) / magnitude(Vector(x, y));
  }

 public:
  long double orthogonalDistance(pair<long long, long long> c) {
    return crossProduct(Vector(x, y), Vector(x, c)) / magnitude(Vector(x, y));
  }

 public:
  pair<long double, long double> intersection(Line l) {
    pair<long double, long double> ans;
    ans.first = (long double)((x.first * y.second - x.second * y.first) *
                                  (l.x.first - l.y.first) -
                              (x.first - y.first) * (l.x.first * l.y.second -
                                                     l.x.second * l.y.first)) /
                ((x.first - y.first) * (l.x.second - l.y.second) -
                 (x.second - y.second) * (l.x.first - l.y.first));
    ans.second =
        (long double)((x.first * y.second - x.second * y.first) *
                          (l.x.second - l.y.second) -
                      (x.second - y.second) *
                          (l.x.first * l.y.second - l.x.second * l.y.first)) /
        ((x.first - y.first) * (l.x.second - l.y.second) -
         (x.second - y.second) * (l.x.first - l.y.first));
    return ans;
  }
};
class PruferCode {
  vector<long long> code;
  vector<pair<long long, long long> > edges;

 public:
  PruferCode(vector<long long> cc) {
    code = cc;
    findEdges();
  }

 private:
  void findEdges() {
    map<long long, long long> mp;
    set<long long> has;
    set<long long> wait;
    for (long long z : code) {
      mp[z]++;
      has.insert(z);
    }
    for (long long i = 0; i < code.size() + 2; i++)
      if (!has.count(i)) wait.insert(i);
    for (long long i = 0; i < code.size(); i++) {
      long long now = *wait.begin();
      edges.push_back(make_pair(now, code[i]));
      mp[now]++;
      mp[code[i]]--;
      if (mp[code[i]] == 0) {
        has.erase(code[i]);
        wait.insert(code[i]);
      }
      wait.erase(now);
    }
    assert(wait.size() == 2);
    edges.push_back(make_pair(*wait.begin(), *wait.rbegin()));
  }

 public:
  vector<pair<long long, long long> > getEdges() { return edges; }
};
class Segment {
  pair<long long, long long> x, y;

 public:
  Segment(pair<long long, long long> a, pair<long long, long long> b) {
    x = a;
    y = b;
  }

 private:
  long double dotProduct(Vector a, Vector b) {
    return a.x.first * b.x.first + a.x.second * b.x.second;
  }

 private:
  long double crossProduct(Vector a, Vector b) {
    return a.x.first * b.x.second - a.x.second * b.x.first;
  }

 private:
  long double magnitude(Vector a) { return a.getMagnitude(); }

 public:
  long double distanceToA(pair<long long, long long> c) {
    return dotProduct(Vector(x, y), Vector(x, c)) / magnitude(Vector(x, y));
  }

 public:
  long double distanceToSegment(pair<long long, long long> c) {
    if (distanceToA(c) >= 0 && distanceToA(c) <= magnitude(Vector(x, y)))
      return crossProduct(Vector(x, y), Vector(x, c)) / magnitude(Vector(x, y));
    else
      return min(magnitude(Vector(x, c)), magnitude(Vector(y, c)));
  }
};
class SegmentTree {
  long long len;
  vector<long long> all;
  vector<long long> seg;

 public:
  SegmentTree(vector<long long> inp) {
    len = inp.size();
    all = inp;
    seg.resize(4 * len);
    build(1, 0, len - 1);
  }
  void build(long long id, long long l, long long r) {
    if (l == r) {
      seg[id] = all[l];
      return;
    }
    long long mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    seg[id] = seg[2 * id] + seg[2 * id + 1];
  }
  void update(long long id, long long l, long long r, long long sl,
              long long sr, long long val) {
    if (r < sl || sr < l) return;
    if (sl <= l && sr >= r) {
      seg[id] += val;
      return;
    }
    long long mid = (l + r) / 2;
    update(2 * id, l, mid, sl, sr, val);
    update(2 * id + 1, mid + 1, r, sl, sr, val);
    seg[id] = seg[2 * id] + seg[2 * id + 1];
  }
  long long query(long long id, long long l, long long r, long long sl,
                  long long sr) {
    if (r < sl || sr < l) return 0;
    if (sl <= l && sr >= r) return seg[id];
    long long mid = (l + r) / 2;
    return (query(2 * id, l, mid, sl, sr) +
            query(2 * id + 1, mid + 1, r, sl, sr));
  }
};
class HopcroftKarp {
  vector<long long> matched;
  vector<vector<pair<long long, long long> > > adj;
  long long left;
  long long right;

 public:
  HopcroftKarp(vector<vector<pair<long long, long long> > > inp, long long l,
               long long r) {
    adj = inp;
    left = l;
    matched.resize(l);
    for (long long i = 0; i < l; i++) matched[i] = -1;
    right = r;
  }

 public:
  vector<long long> match() {
    bool cont = true;
    set<long long> lfree, rfree;
    for (long long i = 0; i < left; i++) lfree.insert(i);
    for (long long i = left; i < left + right; i++) rfree.insert(i);
    vector<bool> yet(left, 0);
    for (long long i = 0; i < left; i++)
      for (long long j = 0; j < adj[i].size(); j++)
        if (adj[i][j].second == 1 && rfree.count(adj[i][j].first) && !yet[i]) {
          yet[i] = true;
          matched[i] = adj[i][j].first;
          adj[i][j].second = 2;
          for (long long x = 0; x < adj[adj[i][j].first].size(); x++)
            if (adj[adj[i][j].first][x].first == i)
              adj[adj[i][j].first][x].second = 2;
          rfree.erase(adj[i][j].first);
          lfree.erase(i);
        }
    while (cont) {
      vector<long long> par(left + right, -1);
      queue<pair<long long, long long> > kyou;
      for (long long z : lfree) kyou.push(make_pair(z, 0));
      long long update = -1;
      vector<long long> vis(left + right, 0);
      while (kyou.size()) {
        pair<long long, long long> frt = kyou.front();
        kyou.pop();
        if (rfree.count(frt.first)) {
          update = frt.first;
          break;
        }
        if (frt.second == 0) {
          for (pair<long long, long long> z : adj[frt.first]) {
            if (z.second == 1 && !vis[z.first]) {
              par[z.first] = frt.first;
              vis[z.first] = 1;
              kyou.push(make_pair(z.first, 1));
            }
          }
        } else {
          for (pair<long long, long long> z : adj[frt.first]) {
            if (z.second == 2 && !vis[z.first]) {
              par[z.first] = frt.first;
              vis[z.first] = 1;
              kyou.push(make_pair(z.first, 0));
            }
          }
        }
      }
      long long x = update;
      long long cnt = 0;
      while (x != -1 && par[x] != -1) {
        for (long long i = 0; i < adj[x].size(); i++)
          if (adj[x][i].first == par[x]) {
            adj[x][i].second = (cnt == 0 ? 2 : 1);
            if (cnt == 0) {
              matched[par[x]] = x;
              rfree.erase(x);
              lfree.erase(par[x]);
            }
          }
        for (long long i = 0; i < adj[par[x]].size(); i++)
          if (adj[par[x]][i].first == x)
            adj[par[x]][i].second = (cnt == 0 ? 2 : 1);
        cnt++;
        cnt %= 2;
        x = par[x];
      }
      if (update == -1) cont = false;
    }
    return matched;
  }
};
class Triangle {
  pair<long long, long long> x, y, z;

 public:
  Triangle(pair<long long, long long> a, pair<long long, long long> b,
           pair<long long, long long> c) {
    x = a;
    y = b;
    z = c;
  }

 private:
  long double crossProduct(Vector a, Vector b) {
    return a.x.first * b.x.second - a.x.second * b.x.first;
  }

 public:
  long double perimeter() {
    long double s1, s2, s3;
    s1 = Vector(x, y).getMagnitude();
    s2 = Vector(y, z).getMagnitude();
    s3 = Vector(x, z).getMagnitude();
    return s1 + s2 + s3;
  }

 public:
  long double area() { return abs(crossProduct(Vector(x, y), Vector(x, z))); }
};
class SuffixArray {
  vector<long long> order;
  vector<long long> lcp;
  string str;

 public:
  SuffixArray(string in) {
    str = in;
    str += '$';
    order.resize(str.length());
    lcp.resize(str.length());
    compute();
  }
  void compute() {
    vector<pair<char, long long> > a;
    vector<long long> equi(order.size());
    vector<long long> bij(order.size());
    for (long long i = 0; i < str.length(); i++)
      a.push_back(make_pair(str[i], i));
    sort(a.begin(), a.end());
    for (long long i = 0; i < str.length(); i++) order[i] = a[i].second;
    equi[order[0]] = 0;
    long long r = 0;
    for (long long i = 1; i < str.length(); i++) {
      if (a[i].first == a[i - 1].first)
        equi[order[i]] = r;
      else
        equi[order[i]] = ++r;
    }
    long long k = 0;
    while ((1 << k) < str.length()) {
      vector<pair<pair<long long, long long>, long long> > a(str.length());
      for (long long i = 0; i < str.length(); i++)
        a[i] = make_pair(
            make_pair(equi[i], equi[(i + (1 << k)) % (str.length())]), i);
      sort(a.begin(), a.end());
      for (long long i = 0; i < str.length(); i++) {
        order[i] = a[i].second;
        bij[order[i]] = i;
      }
      long long r = 0;
      equi[order[0]] = 0;
      for (long long i = 1; i < str.length(); i++) {
        if (a[i].first == a[i - 1].first)
          equi[order[i]] = r;
        else
          equi[order[i]] = ++r;
      }
      k++;
    }
    k = 0;
    for (long long i = 0; i < str.length() - 1; i++) {
      long long p = bij[i];
      long long j = order[p - 1];
      while (i + k < str.length() && j + k < str.length() &&
             str[i + k] == str[j + k])
        k++;
      lcp[p] = k;
      k = max(k - 1, 0LL);
    }
  }

 public:
  long long count(string ptr) {
    long long low = 0;
    long long hi = str.length() - 1;
    long long res1, res2;
    res1 = 0;
    res2 = 1e9;
    while (low <= hi) {
      long long mid = (low + hi) / 2;
      bool gr = false;
      long long i = 0;
      for (i; i < min((long long)ptr.length(),
                      (long long)str.length() - order[mid]);
           i++) {
        if (ptr[i] != str[order[mid] + i]) {
          if (ptr[i] > str[order[mid] + i]) gr = true;
          break;
        }
      }
      if (i == ptr.length()) {
        res2 = min(res2, mid);
        hi = mid - 1;
      } else if (!gr)
        hi = mid - 1;
      else
        low = mid + 1;
    }
    low = 0;
    hi = str.length() - 1;
    while (low <= hi) {
      long long mid = (low + hi) / 2;
      bool gr = false;
      long long i = 0;
      for (i; i < min((long long)ptr.length(),
                      (long long)str.length() - order[mid] + 1);
           i++) {
        if (ptr[i] != str[order[mid] + i]) {
          if (ptr[i] > str[order[mid] + i]) gr = true;
          break;
        }
      }
      if (i == ptr.length()) {
        res1 = max(res1, mid);
        low = mid + 1;
      } else if (!gr)
        hi = mid - 1;
      else
        low = mid + 1;
    }
    if (res2 == 1e9) return 0;
    return (res1 - res2 + 1);
  }

 public:
  vector<long long> get() { return order; }

 public:
  vector<long long> getLcp() { return lcp; }

 public:
  long long diffSubstrings() {
    long long out = 0;
    for (long long i = 1; i < str.length(); i++)
      out += str.length() - order[i] - lcp[i] - 1;
    return out;
  }
};
string longestCommonSubstring(string a, string b) {
  long long len = 0;
  string res = a + '%' + b;
  SuffixArray sf = SuffixArray(res);
  vector<long long> order = sf.get();
  vector<long long> lcp = sf.getLcp();
  vector<long long> col(order.size());
  for (long long i = 0; i < order.size(); i++) {
    if (order[i] < a.length())
      col[order[i]] = 1;
    else if (order[i] > a.length())
      col[order[i]] = 2;
  }
  long long pos = -1;
  for (long long i = 1; i < order.size(); i++)
    if (col[order[i]] + col[order[i - 1]] == 3) {
      if (lcp[i] > len) {
        len = max(len, lcp[i]);
        pos = (col[order[i]] == 1 ? order[i] : order[i - 1]);
      }
    }
  return a.substr(pos, len);
}
class Factorial {
  long long nax;
  vector<long long> fa;
  vector<long long> in;

 public:
  Factorial(long long n) {
    nax = n + 10;
    fa.assign(nax, 1);
    in.resize(nax);
    for (long long i = 1; i < nax; i++) fa[i] = (fa[i - 1] * i) % mod;
    for (long long i = 0; i < nax; i++) in[i] = mbinp(fa[i], mod - 2);
  }

 public:
  long long fac(long long x) { return fa[x]; }

 public:
  long long inv(long long x) { return in[x]; }

 public:
  long long comb(long long x, long long y) {
    if (x < y || x < 0 || y < 0) return 0;
    return (((fa[x] * in[y]) % mod) * in[x - y]) % mod;
  }
};
class WaveletTree {
  vector<vector<long long> > pre;
  long long mx;

 public:
  WaveletTree(vector<long long> &inp, long long delta) {
    pre.resize(4 * inp.size());
    mx = delta + 1;
    build(inp.begin(), inp.end(), 0, mx - 1, 1);
  }
  void build(vector<long long>::iterator b, vector<long long>::iterator e,
             long long l, long long r, long long d) {
    if (l == r) return;
    long long mid = (l + r) / 2;
    pre[d].push_back(0);
    for (vector<long long>::iterator x = b; x != e; x++)
      pre[d].push_back(pre[d].back() + (*x <= mid));
    vector<long long>::iterator p =
        stable_partition(b, e, [=](long long i) { return i <= mid; });
    build(b, p, l, mid, 2 * d);
    build(p, e, mid + 1, r, 2 * d + 1);
  }
  long long occurrenceOf(long long c, long long i) {
    i++;
    long long l = 0;
    long long r = mx - 1;
    long long d = 1;
    long long mid;
    long long shift;
    while (l != r) {
      long long mid = (l + r) / 2;
      shift = pre[d][i];
      d *= 2;
      if (c <= mid) {
        i = shift;
        r = mid;
      } else {
        i -= shift;
        l = mid + 1;
        d++;
      }
    }
    return i;
  }
  long long kthSmallest(long long k, long long i, long long j) {
    j++;
    long long l = 0, r = mx - 1, d = 1, ri, rj;
    while (l != r) {
      long long mid = (l + r) / 2;
      ri = pre[d][i];
      rj = pre[d][j];
      d *= 2;
      if (k <= rj - ri) {
        i = ri;
        j = rj;
        r = mid;
      } else {
        k -= rj - ri;
        i -= ri;
        j -= rj;
        l = mid + 1;
        d++;
      }
    }
    return r;
  }
  long long rectangle(long long i, long long j, long long a, long long b,
                      long long d = 1) {
    if (b < a || j < i) return 0;
    long long l = a, r = b;
    if (b < l || a > r) return 0;
    if (l <= a & r >= b) return j - i;
    long long mid = (a + b) / 2, ri = pre[d][i], rj = pre[d][j];
    return rectangle(ri, rj, a, mid, d * 2) +
           rectangle(i - ri, j - rj, mid + 1, b, 2 * d + 1);
  }
};
class Centroid {
  long long n;
  vector<set<long long> > adj;
  vector<long long> par;
  vector<long long> has;

 public:
  Centroid(vector<vector<long long> > ad) {
    n = ad.size();
    adj.resize(n);
    par.resize(n);
    has.resize(n);
    for (long long i = 0; i < n; i++)
      for (long long z : ad[i]) {
        adj[i].insert(z);
        adj[z].insert(i);
      }
    build(0, -1);
  }
  long long dfs(long long x, long long p) {
    has[x] = 1;
    for (long long z : adj[x])
      if (z != p) has[x] += dfs(z, x);
    return has[x];
  }
  long long centroid(long long x, long long p, long long sz) {
    for (long long z : adj[x])
      if (z != p)
        if (has[z] > sz / 2) return centroid(z, x, sz);
    return x;
  }
  void build(long long x, long long p) {
    long long n = dfs(x, p);
    long long c = centroid(x, p, n);
    if (p == -1) p = c;
    par[c] = p;
    vector<long long> tmp(adj[c].begin(), adj[c].end());
    for (long long z : tmp) {
      adj[z].erase(c);
      adj[c].erase(z);
    }
    for (long long z : tmp) build(z, c);
  }

 public:
  vector<long long> decompose() { return par; }
};
class FenwickSum {
  vector<long long> bit;
  long long n;

 public:
  FenwickSum(vector<long long> inp) {
    n = inp.size();
    bit.assign(n, 0);
    for (long long i = 0; i < n; i++) add(i, inp[i]);
  }
  long long sum(long long r) {
    long long ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
    return ret;
  }

 public:
  long long sum(long long l, long long r) { return sum(r) - sum(l - 1); }

 public:
  void add(long long idx, long long delta) {
    for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;
  }
};
struct seg {
  long long a, b, c, d;
};
const long long N = 10010;
vector<vector<long long> > d(N);
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  vector<seg> all(n);
  vector<vector<pair<long long, long long> > > ver(N);
  vector<vector<pair<long long, long long> > > hor(N);
  for (long long i = 0; i < n; i++) {
    cin >> all[i].a >> all[i].b >> all[i].c >> all[i].d;
    all[i].a += 5000;
    all[i].b += 5000;
    all[i].c += 5000;
    all[i].d += 5000;
    if (all[i].a == all[i].c)
      ver[all[i].a].push_back(
          make_pair(min(all[i].b, all[i].d), max(all[i].b, all[i].d)));
    else
      hor[all[i].b].push_back(
          make_pair(min(all[i].a, all[i].c), max(all[i].a, all[i].c)));
  }
  long long ans = 0;
  for (long long y = 0; y < N; y++) {
    for (pair<long long, long long> s : hor[y]) {
      for (long long i = 0; i < N; i++) d[i].clear();
      vector<long long> dat(10010, 0);
      FenwickSum fen = FenwickSum(dat);
      long long l = s.first;
      long long r = s.second;
      for (long long i = l; i < r + 1; i++)
        for (pair<long long, long long> z : ver[i]) {
          if (y >= z.first && y <= z.second) {
            d[z.second].push_back(i);
            fen.add(i, 1);
          }
        }
      for (long long y2 = y + 1; y2 < N; y2++) {
        for (pair<long long, long long> z : hor[y2]) {
          long long val = fen.sum(z.first, z.second);
          ans += val * (val - 1) / 2;
        }
        for (long long x : d[y2]) fen.add(x, -1);
      }
    }
  }
  cout << ans;
}
