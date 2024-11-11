#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T, class V, int MAX_FREE_FACTOR = (1 << 20), int INIT_m = 3>
struct hash_map {
  struct node {
    T key;
    V val;
    node() {
      key = numeric_limits<T>::min();
      val = numeric_limits<V>::min();
    }
  };
  int size, m, M;
  node* nodes;
  unsigned long long a;
  unsigned long long b;
  T MAX, MIN;
  int min_filled;
  void init() {
    a = uniform_int_distribution<unsigned long long>()(rng);
    if (a % 2 == 0) a++;
    b = uniform_int_distribution<unsigned long long>()(rng);
    m = INIT_m;
    M = 1 << m;
    nodes = new node[M];
    size = 0;
    MAX = numeric_limits<T>::max();
    MIN = numeric_limits<T>::min();
    min_filled = 0;
  }
  hash_map() { init(); }
  int h(T x) { return (((unsigned long long)x) * a + b) >> (64 - m); }
  void rehash(int new_m) {
    int oldM = M;
    node* nodes_copy = new node[M];
    copy(nodes, nodes + M, nodes_copy);
    delete[] nodes;
    M = (1 << new_m);
    m = new_m;
    min_filled = M / MAX_FREE_FACTOR;
    nodes = new node[M];
    size = 0;
    for (int i = 0; i < oldM; i++) {
      T k = nodes_copy[i].key;
      T v = nodes_copy[i].val;
      if (k != MIN && k != MAX) (*this)[k] = v;
    }
    delete[] nodes_copy;
  }
  V& operator[](T x) {
    if (2 * size >= M) {
      rehash(m + 1);
    }
    int pos = h(x);
    while (nodes[pos].key != MIN) {
      if (nodes[pos].key == x) {
        return nodes[pos].val;
      }
      pos = (pos + 1) & (M - 1);
    }
    size++;
    nodes[pos].key = x;
    nodes[pos].val = numeric_limits<V>::min();
    return nodes[pos].val;
  }
  ~hash_map() { delete[] nodes; }
};
const long long INF = 1e15 + 21;
const long long MAXN = 1e5 + 5;
long long N, Q;
long long V[MAXN];
long long C[MAXN];
long long dp[MAXN];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> Q;
  for (long long i = 0; i < N; i++) {
    cin >> V[i];
  }
  for (long long i = 0; i < N; i++) {
    cin >> C[i];
  }
  hash_map<int, long long> curMax;
  for (long long i = 0; i < Q; i++) {
    for (int i = 0; i < N; i++) {
      curMax[C[i]] = -INF;
    }
    long long a, b;
    cin >> a >> b;
    fill(dp, dp + N, -1);
    pair<long long, long long> mx1 = {0, 1e5 + 5};
    pair<long long, long long> mx2 = {0, 1e5 + 4};
    for (long long j = 0; j < N; j++) {
      if (mx1.second == C[j]) {
        dp[j] = mx2.first + b * V[j];
      } else {
        dp[j] = mx1.first + b * V[j];
      }
      dp[j] = max(dp[j], curMax[C[j]] + a * V[j]);
      if (dp[j] > mx1.first) {
        if (C[j] == mx1.second) {
          mx1 = {dp[j], C[j]};
        } else {
          mx2 = {mx1.first, mx1.second};
          mx1 = {dp[j], C[j]};
        }
      } else if (dp[j] > mx2.first) {
        if (C[j] == mx1.second) {
          continue;
        } else {
          mx2 = {dp[j], C[j]};
        }
      }
      curMax[C[j]] = max(curMax[C[j]], dp[j]);
    }
    cout << mx1.first << endl;
  }
}
