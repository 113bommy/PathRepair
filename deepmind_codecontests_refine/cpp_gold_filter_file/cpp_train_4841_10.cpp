#include <bits/stdc++.h>
using namespace std;
set<int> S[250000], T[250000];
set<int>::iterator it;
map<int, int> R;
struct heapnode {
  int ord, num;
  inline bool operator<(const heapnode t) const { return num < t.num; }
};
heapnode heap[250000];
int toheap[250000];
int sum_heap;
inline void heap_swap(int node1, int node2) {
  swap(toheap[heap[node1].ord], toheap[heap[node2].ord]);
  swap(heap[node1], heap[node2]);
  return;
}
inline void heap_up(int node) {
  while ((node > 1) && (heap[node] < heap[node >> 1]))
    heap_swap(node, node >> 1), node = node >> 1;
  return;
}
inline void heap_down(int node) {
  bool left, right;
  for (;;) {
    left = false, right = false;
    if (((node << 1) <= sum_heap) && (heap[node << 1] < heap[node]))
      left = true;
    if (((node << 1 | 1) <= sum_heap) && (heap[node << 1 | 1] < heap[node]))
      right = true;
    if ((left) && (right))
      if (heap[node << 1] < heap[node << 1 | 1])
        right = false;
      else
        left = false;
    if (left) {
      heap_swap(node, node << 1);
      node = node << 1;
      continue;
    }
    if (right) {
      heap_swap(node, node << 1 | 1);
      node = node << 1 | 1;
      continue;
    }
    return;
  }
  return;
}
inline void heap_in(int ord, int num) {
  sum_heap++;
  heap[sum_heap] = (heapnode){ord, num};
  toheap[ord] = sum_heap;
  heap_up(sum_heap);
  return;
}
inline void heap_pushtop() {
  heap_swap(1, sum_heap);
  sum_heap--;
  heap_down(1);
  return;
}
inline void heap_reset(int ord) {
  if (toheap[ord] > sum_heap) return;
  heap[toheap[ord]].num--;
  heap_up(toheap[ord]);
  return;
}
char c[500000];
int i, j, m, n, r, t;
int main() {
  memset(c, 255, sizeof(c));
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%d", &r);
    for (j = 1; j <= r; j++) {
      scanf("%d", &t);
      R[t + m]++;
      T[abs(t)].insert(i);
      S[i].insert(t);
    }
  }
  for (i = 0; i <= 2 * m; i++)
    if (R[i] == 2) {
      t = i;
      if (i <= m)
        t = -(i - m), c[t] = 0;
      else
        t = i - m, c[t] = 1;
      for (it = T[t].begin(); it != T[t].end(); it++) S[*it].clear();
    }
  for (i = 1; i <= n; i++)
    if (S[i].size()) heap_in(i, S[i].size());
  while (sum_heap) {
    t = heap[1].ord;
    heap_pushtop();
    if (S[t].empty()) {
      puts("NO");
      return 0;
    }
    r = *S[t].begin();
    if (r < 0)
      r = -r, c[r] = 0;
    else
      c[r] = 1;
    for (it = T[r].begin(); it != T[r].end(); it++)
      if (*it != t) S[*it].erase(r), S[*it].erase(-r), heap_reset(*it);
    S[t].clear();
  }
  puts("YES");
  for (i = 1; i <= m; i++)
    if (c[i] != -1)
      putchar(c[i] + 48);
    else
      putchar(49);
  return 0;
}
