#include <bits/stdc++.h>
using namespace std;
const int inf = numeric_limits<int>::max();
template <class T>
struct RMQ {
  vector<vector<T>> jmp;
  RMQ(const vector<T>& V) {
    int N = (int)(V).size(), on = 1, depth = 1;
    while (on < (int)(V).size()) on *= 2, depth++;
    jmp.assign(depth, V);
    for (int i = 0; i < (depth - 1); ++i)
      for (int j = 0; j < (N); ++j)
        jmp[i + 1][j] = min(jmp[i][j], jmp[i][min(N - 1, j + (1 << i))]);
  }
  T query(int a, int b) {
    if (b <= a) return inf;
    int dep = 31 - __builtin_clz(b - a);
    return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
  }
};
struct Tree {
  const long long LOW = 1e18;
  long long f(long long a, long long b) { return min(a, b); }
  int n;
  vector<int> s;
  Tree() {}
  Tree(int m, long long def = 0) { init(m, def); }
  void init(int m, long long def) {
    n = 1;
    while (n < m) n *= 2;
    s.assign(n + m, def);
    s.resize(2 * n, LOW);
    for (int i = n; i-- > 1;) s[i] = f(s[i * 2], s[i * 2 + 1]);
  }
  void update(int pos, long long val) {
    pos += n;
    s[pos] = val;
    for (pos /= 2; pos >= 1; pos /= 2) s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
  }
  long long query(int l, int r) { return que(1, l, r, 0, n); }
  long long que(int pos, int l, int r, int lo, int hi) {
    if (r <= lo || hi <= l) return LOW;
    if (l <= lo && hi <= r) return s[pos];
    int m = (lo + hi) / 2;
    return f(que(2 * pos, l, r, lo, m), que(2 * pos + 1, l, r, m, hi));
  }
};
int main() {
  int n, c;
  scanf("%d %d", &n, &c);
  vector<int> a(n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  RMQ<int> rmq(a);
  Tree tree(n);
  tree.update(c - 1, -rmq.query(0, c));
  for (int i = c; i < n; i++) {
    tree.update(
        i, min(tree.query(i - c + 1, i),
               tree.query(i - c, i - c + 1) - rmq.query(i - c + 1, i + 1)));
  }
  cout << sum + tree.query(n - 1, n) << endl;
}
