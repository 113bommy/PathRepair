#include <bits/stdc++.h>
using namespace std;
int tree[300000];
int a[100100];
void updateTree(int s, int e, int ind, int p, int v) {
  if (s == p) {
    tree[ind] = v;
    return;
  }
  if (p >= s && p <= (s + e) / 2) {
    updateTree(s, (s + e) / 2, ind * 2, p, v);
  } else
    updateTree((s + e) / 2 + 1, e, ind * 2 + 1, p, v);
  tree[ind] = max(tree[ind * 2], tree[ind * 2 + 1]);
  return;
}
int getMaxInInterval(int s, int e, int ind, int p) {
  if (s >= p) return tree[ind];
  if ((s + e) / 2 + 1 <= p)
    return getMaxInInterval((s + e) / 2 + 1, e, ind * 2 + 1, p);
  else
    return max(getMaxInInterval(s, (s + e) / 2, ind * 2, p),
               getMaxInInterval((s + e) / 2 + 1, e, ind * 2 + 1, p));
}
int main() {
  int n;
  scanf("%d", &n);
  int maxi = 0;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = n - 1; i >= 0; i--) {
    int ans = getMaxInInterval(1, n, 1, a[i]);
    updateTree(1, n, 1, a[i], ans + 1);
    maxi = max(maxi, ans + 1);
  }
  printf("%d\n", maxi);
}
