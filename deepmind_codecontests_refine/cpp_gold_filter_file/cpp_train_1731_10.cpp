#include <bits/stdc++.h>
using namespace std;
template <class T>
void splitstr(const string &s, vector<T> &out) {
  istringstream in(s);
  out.clear();
  copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
static void redirect(int argc, const char **argv) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  if (argc > 1) {
    static filebuf f;
    f.open(argv[1], ios::in);
    cin.rdbuf(&f);
    if (!cin) {
      cerr << "Failed to open '" << argv[1] << "'" << endl;
      exit(1);
    }
  }
  if (argc > 2) {
    static filebuf f;
    f.open(argv[2], ios::out | ios::trunc);
    cout.rdbuf(&f);
    if (!cout) {
      cerr << "Failed to open '" << argv[2] << "'" << endl;
    }
  }
}
class UnionFind {
 private:
  mutable std::vector<int> parent;

 public:
  explicit UnionFind(int size = 0) : parent(size, -1) {}
  int size() const { return parent.size(); }
  int find(int x) const {
    assert(x >= 0 && x < size());
    int y = x;
    while (parent[y] >= 0) y = parent[y];
    while (parent[x] >= 0) {
      int nxt = parent[x];
      parent[x] = y;
      x = nxt;
    }
    return y;
  }
  bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (-parent[x] > -parent[y]) std::swap(x, y);
    parent[y] += parent[x];
    parent[x] = y;
    return true;
  }
  int component_size(int x) const { return -parent[find(x)]; }
};
struct princess {
  int a, b;
  long long w;
  bool operator<(const princess &other) const { return w > other.w; }
};
int main(int argc, const char **argv) {
  redirect(argc, argv);
  int N, M;
  cin >> N >> M;
  UnionFind uf(N);
  vector<bool> full(N);
  long long ans = 0;
  vector<princess> P(M);
  for (int i = 0; i < M; i++) {
    cin >> P[i].a >> P[i].b >> P[i].w;
    P[i].a--;
    P[i].b--;
  }
  sort(begin(P), end(P));
  for (const princess &p : P) {
    int a = uf.find(p.a);
    int b = uf.find(p.b);
    bool fa = full[a];
    bool fb = full[b];
    if (fa && fb) continue;
    ans += p.w;
    if (a == b)
      full[a] = true;
    else {
      uf.merge(a, b);
      int root = uf.find(a);
      full[root] = fa || fb;
    }
  }
  cout << ans << '\n';
  return 0;
}
