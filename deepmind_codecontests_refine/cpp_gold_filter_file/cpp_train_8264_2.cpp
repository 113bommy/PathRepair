#include <bits/stdc++.h>
using namespace std;
int const N = 200020;
int t[N * 4];
int up(int node, int start, int end, int ind, long long v, int op) {
  if (start > ind || end < ind) return t[node];
  if (start == end) return t[node] = v;
  int mid = (start + end) / 2;
  up(node * 2, start, mid, ind, v, op ^ 1);
  up(node * 2 + 1, mid + 1, end, ind, v, op ^ 1);
  if (!op) {
    t[node] = (t[node * 2] | t[node * 2 + 1]);
  } else
    t[node] = (t[node * 2] ^ t[node * 2 + 1]);
  return t[node];
}
int main() {
  int a, q;
  scanf("%d%d", &a, &q);
  for (int i = 1; i <= (1 << a); ++i) {
    int v;
    scanf("%d", &v);
    up(1, 1, (1 << a), i, v, !(a & 1));
  }
  while (q--) {
    int ind, val;
    scanf("%d%d", &ind, &val);
    printf("%d\n", up(1, 1, (1 << a), ind, val, !(a & 1)));
  }
  return 0;
}
