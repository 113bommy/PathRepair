#include <bits/stdc++.h>
using namespace std;
void itval(istream_iterator<string> it) {}
template <typename T, typename... Args>
void itval(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  itval(++it, args...);
}
const long long int MOD = 1e9 + 7;
template <typename T>
inline void print(T x) {
  cout << x << "\n";
}
template <typename T>
inline void printvec(T x) {
  for (auto a : x) cout << a << ' ';
  cout << '\n';
}
struct custom {
  bool operator()(const pair<int, pair<int, int> > &p1,
                  const pair<int, pair<int, int> > &p2) const {
    return p1.first > p2.first;
  }
};
long long int get_pow(long long int a, long long int b, long long int M = MOD) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = (res * a) % M;
    a = (a * a) % M;
    b >>= 1;
  }
  return res;
}
const long long int N = 1e5 + 5, inf = 2e18;
int ans, segs;
multiset<int> have;
class DSU {
  int parent[N];
  long long int si[N];

 public:
  void init() { memset(si, 0, sizeof si); }
  void make_set(int v) {
    parent[v] = v;
    si[v] = 1;
    have.insert(1);
  }
  int find_set(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find_set(parent[x]);
  }
  void union_sets(int a, int b) {
    int x = find_set(a);
    int y = find_set(b);
    if (x != y) {
      have.erase(have.find(si[x]));
      have.erase(have.find(si[y]));
      if (si[x] < si[y]) swap(x, y);
      parent[y] = x;
      si[x] += si[y];
      have.insert(si[x]);
    }
  }
  long long int get_size(int v) { return si[find_set(v)]; }
  bool present(int i) { return (si[i] != 0); }
};
DSU dsu;
void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    int x;
    cin >> x;
    cout << x << '\n';
    return;
  }
  dsu.init();
  std::vector<pair<int, int> > v(n);
  for (long long int i = (long long int)0; i < (long long int)(n); i++) {
    cin >> v[i].first;
    v[i].second = i;
  }
  sort(v.begin(), v.end());
  ans = v[0].first, segs = 1;
  for (auto x : v) {
    int i = x.second;
    dsu.make_set(i);
    if (i - 1 >= 0 && dsu.present(i - 1)) dsu.union_sets(i, i - 1);
    if (i + 1 < n && dsu.present(i + 1)) dsu.union_sets(i, i + 1);
    if (*have.begin() == *have.rbegin()) {
      if (have.size() > segs) {
        segs = have.size();
        ans = x.first;
      }
    }
  }
  ans++;
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test = 1;
  clock_t z = clock();
  for (long long int tes = (long long int)0; tes < (long long int)(test);
       tes++) {
    solve();
  }
  fprintf(stderr, "Total Time:%.4f\n", (double)(clock() - z) / CLOCKS_PER_SEC),
      fflush(stderr);
  return 0;
}
