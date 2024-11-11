#include <bits/stdc++.h>
using namespace std;
template <class T>
T nextInt() {
  T x = 0, p = 1;
  char c;
  do {
    c = getchar();
  } while (c <= 32);
  if (c == '-') {
    p = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * p;
}
const int maxTime = 100500, maxWeight = 4010, maxQ = 20500;
struct item {
  int c, h;
  item() {}
  item(int c, int h) : c(c), h(h) {}
};
struct query {
  int l, r, idx, cap;
  query() {}
  query(int l, int r, int idx, int cap) : l(l), r(r), idx(idx), cap(cap) {}
};
int n, p, q;
vector<item> items[maxTime];
vector<query> queries[maxTime];
int result[maxQ];
struct knapsack {
  int f[maxWeight];
  knapsack() {}
  void addItem(item x) {
    for (int i = maxWeight - x.c - 1; i >= 0; i--)
      if (f[i] + x.h > f[i + x.c]) f[i + x.c] = f[i] + x.h;
  }
  void init() { memset(f, 0, sizeof(f)); }
};
bool notDelete[maxTime];
knapsack* K[maxTime];
void processQuery(query q, int T) {
  if (q.l < 0) q.l = 0;
  if (q.r >= maxTime) q.r = maxTime - 1;
  if (q.l >= maxTime) return;
  if (q.r == T) {
    result[q.idx] = *max_element(K[q.l]->f, K[q.l]->f + q.cap + 1);
    return;
  }
  result[q.idx] = 0;
  for (int leftC = 0; leftC <= q.cap; leftC++) {
    int cur = K[q.l]->f[leftC] + K[q.r]->f[q.cap - leftC];
    if (cur > result[q.idx]) result[q.idx] = cur;
  }
}
void process(int idx) {
  int T = idx * p;
  int l = max(0, T - p + 1);
  int r = min(maxTime - 1, T + p - 1);
  K[T] = new knapsack();
  K[T]->init();
  for (int i = l; i <= r; i++) notDelete[i] = false;
  for (int i = T; i >= l; i--) {
    if (i != T && items[i].empty()) {
      K[i] = K[i + 1];
      notDelete[i] = true;
      continue;
    }
    if (i != T) {
      K[i] = new knapsack();
      memcpy(K[i], K[i + 1], sizeof(knapsack));
    }
    for (size_t it = 0; it < items[i].size(); it++) {
      K[i]->addItem(items[i][it]);
    }
  }
  K[T + 1] = new knapsack();
  K[T + 1]->init();
  for (int i = T + 1; i <= r; i++) {
    if (i != T + 1 && items[i].empty()) {
      K[i] = K[i - 1];
      notDelete[i] = true;
      continue;
    }
    if (i != T + 1) {
      K[i] = new knapsack();
      memcpy(K[i], K[i - 1], sizeof(knapsack));
    }
    for (size_t it = 0; it < items[i].size(); it++) {
      K[i]->addItem(items[i][it]);
    }
  }
  for (size_t i = 0; i < queries[idx].size(); i++) {
    processQuery(queries[idx][i], T);
  }
  for (int i = l; i <= r; i++)
    if (!notDelete[i]) delete K[i];
}
int main() {
  n = nextInt<int>();
  p = nextInt<int>();
  for (int i = 1; i <= n; i++) {
    int c, h, t;
    c = nextInt<int>();
    h = nextInt<int>();
    t = nextInt<int>();
    items[t].push_back(item(c, h));
  }
  q = nextInt<int>();
  int maxIdx = 0;
  for (int i = 1; i <= q; i++) {
    int l, r, cap;
    r = nextInt<int>();
    l = r - p + 1;
    cap = nextInt<int>();
    int z = (l / p) * p;
    while (z < l) z += p;
    maxIdx = max(maxIdx, z / p);
    queries[z / p].push_back(query(l, r, i, cap));
  }
  for (int i = 0; i <= maxIdx; i++) {
    if (queries[i].empty()) continue;
    process(i);
  }
  for (int i = 1; i <= q; i++) printf("%d\n", result[i]);
  return 0;
}
