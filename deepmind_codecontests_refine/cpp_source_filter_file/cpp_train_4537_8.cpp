#include <bits/stdc++.h>
using namespace std;
int tree[4000005];
void update(int node, int L, int R, int a) {
  if (R < a || L > a || R < L) return;
  if (L == R) {
    tree[node]++;
    return;
  }
  int mid = (L + R) >> 1;
  update((node << 1), L, mid, a);
  update(((node << 1) + 1), mid + 1, R, a);
  tree[node] = tree[(node << 1)] + tree[((node << 1) + 1)];
}
int query(int node, int L, int R, int a, int b) {
  if (R < a || L > b) return 0;
  if (R < L) return 0;
  if (R <= b && L >= a) return tree[node];
  int mid = (L + R) >> 1;
  return query((node << 1), L, mid, a, b) +
         query(((node << 1) + 1), mid + 1, R, a, b);
}
int main() {
  int n, k, nxt, tmp;
  cin >> n >> k;
  int i = 0;
  long long ans = 1;
  for (int j = 0; j < n; j++) {
    nxt = i + k;
    if (nxt >= n) nxt -= n;
    if (i < nxt) {
      if (nxt - i > n - nxt + i)
        tmp = query(1, 0, n - 1, i + 1, n - 1) + query(1, 0, n - 1, 0, nxt - 1);
      else
        tmp = query(1, 0, n - 1, i + 1, nxt - 1);
    } else {
      if (n - i + nxt > i - nxt)
        tmp = query(1, 0, n - 1, nxt + 1, i - 1);
      else
        tmp = query(1, 0, n - 1, i + 1, n - 1) + query(1, 0, n - 1, 0, nxt - 1);
    }
    update(1, 0, n - 1, i);
    update(1, 0, n - 1, nxt);
    i = nxt;
    ans += (tmp + 1);
    printf("%I64d ", ans);
  }
  puts("");
  return 0;
}
