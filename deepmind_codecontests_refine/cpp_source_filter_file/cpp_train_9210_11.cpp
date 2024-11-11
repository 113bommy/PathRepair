#include <bits/stdc++.h>
using namespace std;
vector<long long> tree, mod;
long long s = 1;
const long long INF = 1000000000;
void build(vector<long long> &V) {
  long long n = V.size();
  while (s < n) s *= 2;
  tree.resize(2 * s, 0);
  mod.resize(2 * s, 0);
  for (long long i = 0; i < n; i++) {
    tree[i + s] = V[i];
  }
  for (long long i = s - 1; i > 0; --i) {
    tree[i] = min(tree[2 * i], tree[2 * i + 1]);
  }
}
void push(long long v, long long tl, long long tr) {
  if (tl == tr) {
    tree[v] += mod[v];
    mod[v] = 0;
    return;
  }
  mod[2 * v] += mod[v];
  mod[2 * v + 1] += mod[v];
  tree[v] += mod[v];
  mod[v] = 0;
}
long long get(long long v, long long tl, long long tr, long long l,
              long long r) {
  if (tr < l || tl > r) return INF;
  push(v, tl, tr);
  if (l <= tl && tr <= r) {
    return tree[v];
  }
  long long tm = (tl + tr) / 2;
  return min(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}
long long get(long long l, long long r) { return get(1, 0, s - 1, l, r); }
void update(long long v, long long tl, long long tr, long long l, long long r,
            long long val) {
  if (l > tr || r < tl) {
    push(v, tl, tr);
    return;
  }
  if (l <= tl && tr <= r) {
    mod[v] += val;
    push(v, tl, tr);
    return;
  }
  push(v, tl, tr);
  long long tm = (tl + tr) / 2;
  update(2 * v, tl, tm, l, r, val);
  update(2 * v + 1, tm + 1, tr, l, r, val);
  tree[v] = min(tree[2 * v], tree[2 * v + 1]);
}
void update(long long l, long long r, long long val) {
  update(1, 0, s - 1, l, r, val);
}
int main() {
  ios_base::sync_with_stdio(false);
  long long N = 0, M = 0;
  cin >> N;
  vector<long long> V(N, 0);
  for (long long i = 0; i < N; ++i) {
    cin >> V[i];
  }
  build(V);
  cin >> M;
  for (long long i = 0; i < M; i++) {
    long long L = 0, R = 0;
    cin >> L >> R;
    if (cin.peek() == '\n') {
      if (R >= L)
        cout << get(L, R) << '\n';
      else
        cout << min(get(L, N - 1), get(0, R)) << "\n";
    } else {
      long long val = 0;
      cin >> val;
      if (R >= L)
        update(L, R, val);
      else {
        update(L, N - 1, val);
        update(0, R, val);
      }
    }
  }
  return 0;
}
