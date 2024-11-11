#include <bits/stdc++.h>
using namespace std;
const int SIZE = 2 * 100009;
struct Node {
  long long int inc;
  long long int max;
} nodes[SIZE * 8];
void inc(int idx, int l, int r, int s, int e, long long int d) {
  if (s <= l && r <= e) {
    nodes[idx].inc += d;
    nodes[idx].max += d;
  } else {
    int m = (l + r) >> 1;
    if (nodes[idx].inc) {
      inc(idx * 2, l, m, l, m, nodes[idx].inc);
      inc(idx * 2 + 1, m, r, m, r, nodes[idx].inc);
      nodes[idx].inc = 0;
    }
    if (s < m) inc(idx * 2, l, m, s, e, d);
    if (e > m) inc(idx * 2 + 1, m, r, s, e, d);
    nodes[idx].max = max(nodes[idx * 2].max, nodes[idx * 2 + 1].max);
  }
}
long long int query(int idx, int l, int r, int s, long long int e) {
  if (s <= l && r <= e)
    return nodes[idx].max;
  else {
    int m = (l + r) >> 1;
    if (nodes[idx].inc) {
      inc(idx * 2, l, m, l, m, nodes[idx].inc);
      inc(idx * 2 + 1, m, r, m, r, nodes[idx].inc);
      nodes[idx].inc = 0;
    }
    if (s >= m)
      return query(idx * 2 + 1, m, r, s, e);
    else if (e <= m)
      return query(idx * 2, l, m, s, e);
    else
      return max(query(idx * 2, l, m, s, e), query(idx * 2 + 1, m, r, s, e));
  }
}
int cs[SIZE];
struct Race {
  int a, b, c;
  bool operator<(const Race& other) const { return b < other.b; }
} races[SIZE];
int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++) scanf("%d", cs + i);
  for (int i = 0; i < M; i++)
    scanf("%d%d%d", &races[i].a, &races[i].b, &races[i].c);
  sort(races, races + M);
  long long int ans = 0;
  for (int i = 1, j = 0; i <= N; i++) {
    long long int t = query(1, 0, N + 1, i - 1, i);
    long long int cost = cs[i];
    inc(1, 0, N + 1, 0, i, -cost);
    while (j < M && races[j].b == i) {
      inc(1, 0, N + 1, 0, races[j].a, races[j].c);
      j++;
    }
    long long op = max(t, query(1, 0, N + 1, 0, i));
    ans = max(ans, op);
    inc(1, 0, N + 1, i, i + 1, ans);
  }
  printf("%I64d\n", ans);
  return 0;
}
