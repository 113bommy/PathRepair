#include <bits/stdc++.h>
using namespace std;
const int mx = 500005;
int arr[mx], tree[mx];
bool can[mx];
void update(int idx) {
  int i;
  for (i = idx; i < mx; i += (i & -i)) {
    tree[i] += 1;
  }
}
int query(int idx) {
  int sum = 0;
  for (int i = idx; i > 0; i -= (i & -i)) {
    sum += tree[i];
  }
  return sum;
}
int main() {
  int n, k, d, i, j, p, l, r;
  scanf("%d %d %d", &n, &k, &d);
  for (i = 1; i <= n; i++) scanf("%d", arr + i);
  sort(arr + 1, arr + n + 1);
  if (arr[k] - arr[1] > d) return !printf("NO\n");
  for (i = 1; i <= k; i++) {
    update(i);
    can[i] = 1;
  }
  for (i = k + 1; i <= n; i++) {
    r = i - k;
    l = lower_bound(arr + 1, arr + n + 1, arr[i] - d) - arr - 1;
    if (arr[i] - arr[1] <= d) {
      can[i] = 1;
      update(i);
      continue;
    }
    if (l < k) l = k;
    if (l > r) {
      can[i] = 0;
      continue;
    }
    p = query(r) - query(l - 1);
    if (p) {
      update(i);
      can[i] = 1;
    } else {
      can[i] = 0;
    }
  }
  if (can[n])
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
