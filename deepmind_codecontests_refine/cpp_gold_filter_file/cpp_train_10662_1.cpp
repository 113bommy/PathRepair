#include <bits/stdc++.h>
using namespace std;
inline int rei() {
  int x;
  cin >> x;
  return x;
}
inline long long rel() {
  long long x;
  cin >> x;
  return x;
}
inline string res() {
  string x;
  cin >> x;
  return x;
}
class Monoid {
 public:
  using t = int;
  static t id() { return 0; }
  static t op(const t& l, const t& r) { return l + r; }
};
template <typename M>
class SegmentTree {
  using T = typename M::t;
  const int n;
  vector<T> data;
  int size(int n_) {
    int res = 1;
    while (res < n_) {
      res <<= 1;
    }
    return res;
  }

 public:
  SegmentTree(int n_) : n(size(n_)), data(n * 2, M::id()) {}
  SegmentTree(int n_, T v) : n(size(n_)), data(n * 2, v) {}
  SegmentTree(const vector<T>& data_)
      : n(size(data_.size())), data(n * 2, M::id()) {
    init(data_);
  }
  void init() {
    for (int i = n - 1; i >= 1; i--)
      data[i] = M::op(data[i * 2], data[i * 2 + 1]);
  }
  void init(const vector<T>& data_) {
    for (int i = 0; i < (int)data_.size(); i++) data[i + n] = data_[i];
    init();
  }
  T Query(int k) {
    k += n;
    T ans = data[k];
    while (k >>= 1) {
      ans = M::op(ans, data[k]);
    }
    return ans;
  }
  void Update(int a, int b, const T x) {
    for (a += n, b += n; a < b; a >>= 1, b >>= 1) {
      if (a & 1) data[a] = M::op(data[a], x), a++;
      if (b & 1) b--, data[b] = M::op(data[b], x);
    }
  }
};
bool Depth[200000];
int A[200000];
int childt[200000];
int vtoo[200000];
vector<int> G[200000];
void Calc() {
  int N = rei();
  int M = rei();
  for (int i = 0; i < N; i++) {
    A[i] = rei();
  }
  for (int i = 0; i < N - 1; i++) {
    int f = rei() - 1;
    int t = rei() - 1;
    G[f].push_back(t);
    G[t].push_back(f);
  }
  stack<pair<int, int>> sp;
  int c = 0;
  sp.push({0, -1});
  while (!sp.empty()) {
    int v = sp.top().first;
    int f = sp.top().second;
    sp.pop();
    if (v >= N) {
      v -= N;
      childt[v] = c;
    } else {
      if (f == -1) {
        Depth[v] = false;
      } else {
        Depth[v] = !Depth[f];
      }
      vtoo[v] = c;
      c++;
      sp.push({v + N, f});
      for (int i = 0; i < G[v].size(); i++) {
        int t = G[v][i];
        if (t != f) {
          sp.push({t, v});
        }
      }
    }
  }
  SegmentTree<Monoid> Seg(N);
  for (int i = 0; i < M; i++) {
    int type = rei();
    if (type == 1) {
      int x = rei() - 1;
      int val = rei();
      if (Depth[x]) {
        val = -val;
      }
      Seg.Update(vtoo[x], childt[x], val);
    } else {
      int x = rei() - 1;
      int ans = Seg.Query(vtoo[x]);
      if (Depth[x]) {
        ans = -ans;
      }
      ans += A[x];
      cout << ans << "\n";
    }
  }
}
int main(int argc, char** argv) {
  ios::sync_with_stdio(false), cin.tie(0);
  cout.tie(0);
  Calc();
  return 0;
}
