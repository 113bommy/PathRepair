#include <bits/stdc++.h>
using namespace std;
const int MAX = 0x3f3f3f3f;
int n, k, a[35001], dp[35001][55];
int tree[55][35001], ever[55][35001];
int put(int k, int a, int b, int l, int r, int id, int val) {
  if (r <= a || l >= b) {
    return tree[id][k] + ever[id][k];
  }
  if (r <= b && l >= a) {
    ever[id][k] += val;
    return tree[id][k] + ever[id][k];
  }
  int mid = (l + r) >> 1;
  return (tree[id][k] = max(put(k * 2, a, b, l, mid, id, val),
                            put(k * 2 + 1, a, b, mid, r, id, val))) +
         ever[id][k];
}
int find(int k, int a, int b, int l, int r, int id) {
  if (r <= a || l >= b) return 0;
  if (r <= b && l >= a) {
    return ever[id][k] + tree[id][k];
  }
  int mid = (l + r) >> 1;
  return max(find(k * 2, a, b, l, mid, id), find(k * 2 + 1, a, b, mid, r, id)) +
         ever[id][k];
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i <= n - 1; i++) scanf("%d", &a[i]);
  int pre[35001], last[35001];
  memset(last, 0, sizeof(last));
  map<int, int> m;
  int tohere[35001] = {0};
  for (int i = 0; i <= n - 1; i++) {
    tohere[i] = tohere[max(0, i - 1)];
    if (!m[a[i]]) {
      m[a[i]] = 1;
      tohere[i]++;
    }
    pre[i] = last[a[i]];
    last[a[i]] = i;
  }
  int startn = n;
  n = 1 << int(ceil(log2(double(n))));
  for (int j = 1; j <= k; j++) {
    for (int i = 0; i <= startn - 1; i++) {
      put(1, pre[i], i, 0, n, j - 1, 1);
      if (i == 0) {
        dp[i][j] = 1;
      } else {
        if (j == 1)
          dp[i][j] = tohere[i];
        else
          dp[i][j] = find(1, 0, i, 0, n, j - 1);
      }
      put(1, i, i + 1, 0, n, j, dp[i][j]);
    }
  }
  printf("%d\n", dp[startn - 1][k]);
  return 0;
}
