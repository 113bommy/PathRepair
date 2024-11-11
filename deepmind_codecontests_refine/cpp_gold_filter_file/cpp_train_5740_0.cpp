#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
template <typename T>
class BIT {
 private:
  int n, sz;
  vector<T> node;

 public:
  BIT(int sz) : n(1), sz(sz) {
    while (n < sz) n *= 2;
    node.resize(n, 0);
  }
  void add(int i, T x) {
    i++;
    while (i <= n) {
      node[i] += x;
      i += i & -i;
    }
  }
  T sum(int i) {
    if (i < 0) return 0;
    T s = 0;
    i++;
    while (i) {
      s += node[i];
      i -= i & -i;
    }
    return s;
  }
};
const int MAX = 2e5 + 10;
int n, m, a[MAX], b[MAX];
vector<BIT<int>> bit(225, BIT<int>(MAX));
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int w = 1000;
  cin >> n >> m;
  int buf;
  for (long long i = (0); i < (n); i++) {
    cin >> buf;
    a[buf] = i;
  }
  for (long long i = (0); i < (n); i++) {
    cin >> buf;
    b[i] = a[buf];
  }
  for (long long i = (0); i < (n); i++) bit[i / w].add(b[i], 1);
  for (long long i = (0); i < (m); i++) {
    int f;
    cin >> f;
    if (f == 1) {
      int la, ra, lb, rb;
      cin >> la >> ra >> lb >> rb;
      la--;
      lb--;
      ra--;
      long long ans = 0;
      while (lb < rb && lb % w != 0) {
        if (la <= b[lb] && b[lb] <= ra) ans++;
        lb++;
      }
      while (lb < rb && rb % w != 0) {
        rb--;
        if (la <= b[rb] && b[rb] <= ra) ans++;
      }
      while (lb < rb) {
        ans += bit[lb / w].sum(ra) - bit[lb / w].sum(la - 1);
        lb += w;
      }
      cout << (ans) << endl;
    } else {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      bit[x / w].add(b[x], -1);
      bit[y / w].add(b[y], -1);
      int tmp = b[x];
      b[x] = b[y];
      b[y] = tmp;
      bit[x / w].add(b[x], 1);
      bit[y / w].add(b[y], 1);
    }
  }
  return 0;
}
