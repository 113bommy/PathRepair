#include <bits/stdc++.h>
using namespace std;
template <class T>
T inf() {
  return (numeric_limits<T>::max() >> 1);
}
FILE *file_in = stdin, *file_out = stdout;
struct NORMAL_IN {
  bool cnt;
  NORMAL_IN() : cnt(true) {}
  operator int() const { return cnt; }
  NORMAL_IN &operator>>(int &n) {
    cnt = fscanf(file_in, "%d", &n) != EOF;
    return *this;
  }
  NORMAL_IN &operator>>(unsigned int &n) {
    cnt = fscanf(file_in, "%u", &n) != EOF;
    return *this;
  }
  NORMAL_IN &operator>>(long long &n) {
    cnt = fscanf(file_in, "%lld", &n) != EOF;
    return *this;
  }
  NORMAL_IN &operator>>(unsigned long long &n) {
    cnt = fscanf(file_in, "%llu", &n) != EOF;
    return *this;
  }
  NORMAL_IN &operator>>(double &n) {
    cnt = fscanf(file_in, "%lf", &n) != EOF;
    return *this;
  }
  NORMAL_IN &operator>>(long double &n) {
    cnt = fscanf(file_in, "%Lf", &n) != EOF;
    return *this;
  }
  NORMAL_IN &operator>>(char *c) {
    cnt = fscanf(file_in, "%s", c) != EOF;
    return *this;
  }
  NORMAL_IN &operator>>(string &s) {
    s.clear();
    for (bool r = false;;) {
      const char c = getchar();
      if (c == EOF) {
        cnt = false;
        break;
      }
      const int t = isspace(c);
      if (!r and !t) r = true;
      if (r) {
        if (!t)
          s.push_back(c);
        else
          break;
      }
    }
    return *this;
  }
  template <class T>
  NORMAL_IN &operator>>(vector<T> &v) {
    int n;
    fscanf(file_in, "%d", &n);
    for (int i = 0; i < (int)(n); ++i) {
      T t;
      *this >> t;
      v.push_back(t);
    }
    return *this;
  }
} normal_in;
struct NORMAL_OUT {
  NORMAL_OUT &operator<<(const int &n) {
    fprintf(file_out, "%d", n);
    return *this;
  }
  NORMAL_OUT &operator<<(const unsigned int &n) {
    fprintf(file_out, "%u", n);
    return *this;
  }
  NORMAL_OUT &operator<<(const long long &n) {
    fprintf(file_out, "%lld", n);
    return *this;
  }
  NORMAL_OUT &operator<<(const unsigned long long &n) {
    fprintf(file_out, "%llu", n);
    return *this;
  }
  NORMAL_OUT &operator<<(const double &n) {
    fprintf(file_out, "%lf", n);
    return *this;
  }
  NORMAL_OUT &operator<<(const long double &n) {
    fprintf(file_out, "%Lf", n);
    return *this;
  }
  NORMAL_OUT &operator<<(const char c[]) {
    fprintf(file_out, "%s", c);
    return *this;
  }
  NORMAL_OUT &operator<<(const string &s) {
    fprintf(file_out, "%s", s.c_str());
    return *this;
  }
} normal_out;
struct ERR_OUT {
  template <class T>
  ERR_OUT &operator<<(const T &a) {
    cerr << "\x1b[7m" << a << "\x1b[m";
    return *this;
  }
} ferr;
template <class Weight>
struct edge {
  int src, dst;
  Weight weight;
  int rev;
  edge(int src, int dst, Weight weight = 1, int rev = -1)
      : src(src), dst(dst), weight(weight), rev(rev) {}
};
template <class Weight>
bool operator<(const edge<Weight> &e, const edge<Weight> &f) {
  return e.weight != f.weight ? e.weight > f.weight
         : e.src != f.src     ? e.src < f.src
                              : e.dst < f.dst;
}
template <class Weight>
struct matrix : vector<vector<Weight> > {
  matrix(const array<int, 2> &a, Weight w = 0)
      : vector<vector<Weight> >(a[0], vector<Weight>(a[1], w)) {}
  matrix(const array<int, 1> &a, Weight w = 0)
      : vector<vector<Weight> >(a[0], vector<Weight>(a[0], 0)) {}
  matrix() {}
};
template <class Weight>
struct graph : vector<vector<edge<Weight> > > {
  Weight inf{::inf<Weight>()};
  graph() {}
  graph(const int &n) : vector<vector<edge<Weight> > >(n) {}
  void _add_edge(int from, int to, Weight w, int rev = -1) {
    if ((int)this->size() < from + 1) this->resize(from + 1);
    this->at(from).push_back(edge<Weight>(from, to, w, rev));
  }
};
template <class Weight>
void addBiEdge(graph<Weight> &g, const pair<int, int> &e, Weight w = 1) {
  const int &from = e.first, &to = e.second;
  g._add_edge(from, to, w, g[to].size());
  g._add_edge(to, from, w, g[from].size() - 1);
}
template <class Weight>
void addEdge(graph<Weight> &g, const pair<int, int> &e, Weight w = 1) {
  const int &from = e.first, &to = e.second;
  g._add_edge(from, to, w);
}
template <class T>
void matrix_out(const vector<vector<T> > &x) {
  for (int i = 0; i < (int)(x.size()); ++i) {
    for (int j = 0; j < (int)(x[0].size()); ++j) {
      cout << x[i][j] << "\t";
    }
    cout << "\n";
  }
}
template <class U, class S, class T>
U &operator<<(U &os, const pair<S, T> &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
void printBit(int b, int k = -1) {
  if (k == -1) {
    int bb = 1, i = 0;
    while (bb) {
      if (b & bb) k = i;
      bb <<= 1;
      i++;
    }
  }
  for (int ct = 0; ct < (int)(k); ++ct) {
    cout << b % 2;
    b >>= 1;
  }
  cout << "\n";
}
template <typename U, template <typename... Args> class Container,
          typename... Types>
U &operator<<(U &os, const Container<Types...> &x) {
  os << "{";
  for (const auto &e : x) os << " " << e << " ";
  os << "}";
  return os;
}
graph<int> g;
vector<long long> size, a, b, c;
long long two_vec(const vector<long long> &x, const vector<long long> &y) {
  long long sx = 0, sy = 0, sxy = 0;
  for (int i = 0; i < (int)(x.size()); ++i)
    sx += x[i], sy += y[i], sxy += x[i] * y[i];
  return sx * sy - sxy;
}
long long three_vec(const vector<long long> &x, const vector<long long> &y,
                    const vector<long long> &z) {
  long long sx = 0, sy = 0, sz = 0, sxy = 0, syz = 0, szx = 0, sxyz = 0;
  for (int i = 0; i < (int)(x.size()); ++i)
    sx += x[i], sy += y[i], sz += z[i], sxy += x[i] * y[i], syz += y[i] * z[i],
        szx += z[i] * x[i], sxyz += x[i] * y[i] * z[i];
  return sx * sy * sz - sx * syz - sy * szx - sz * sxy + 2 * sxyz;
}
void dfs(int u, int p) {
  size[u] = 1;
  vector<int> vs;
  for (auto &&e : g[u]) {
    int v = e.dst;
    if (v == p) continue;
    dfs(v, u);
    size[u] += size[v];
    vs.push_back(v);
  }
  long long s;
  vector<long long> a_vec, b_vec, size_vec;
  long long a_vec_sum = 0, b_vec_sum = 0, size_vec_sum = 0;
  for (auto &&v : vs) {
    a_vec.push_back(a[v]);
    b_vec.push_back(b[v]);
    size_vec.push_back(size[v]);
    a_vec_sum += a[v];
    b_vec_sum += b[v];
    size_vec_sum += size[v];
  }
  s = 0;
  s += a_vec_sum;
  s += size_vec_sum;
  s += two_vec(size_vec, size_vec) / 2;
  a[u] = s;
  s = 0;
  long long a_size_two_vec = two_vec(a_vec, size_vec);
  s += a_size_two_vec;
  s += b_vec_sum;
  long long tmp = s;
  s += a_vec_sum;
  b[u] = s;
  s = 0;
  for (auto &&v : vs) s += c[v];
  s += two_vec(a_vec, a_vec);
  s += tmp;
  s += three_vec(a_vec, size_vec, size_vec) / 2;
  s += two_vec(b_vec, size_vec);
  c[u] = s;
}
int main() {
  int n;
  normal_in >> n;
  g.assign(n, vector<edge<int> >());
  for (int i = 0; i < (int)(n - 1); ++i) {
    int u, v;
    normal_in >> u >> v;
    u--;
    v--;
    addBiEdge(g, {u, v});
  }
  size.assign(n, 0);
  a.assign(n, 0);
  b.assign(n, 0);
  c.assign(n, 0);
  dfs(0, -1);
  normal_out << b[0] / 2 << "\n";
  return 0;
}
