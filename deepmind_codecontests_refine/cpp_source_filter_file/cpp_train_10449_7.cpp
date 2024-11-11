#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int maxm = 7e5;
int T[maxn];
int cnt[maxn], lson[maxn], rson[maxn], clk;
void insert(int pre, int &rt, int L, int R, int pos) {
  rt = ++clk;
  cnt[rt] = cnt[pre] + 1;
  if (L == R) return;
  int mid = L + R >> 1;
  if (pos <= mid) {
    rson[rt] = rson[pre];
    insert(lson[pre], lson[rt], L, mid, pos);
  } else {
    lson[rt] = lson[pre];
    insert(rson[pre], rson[rt], mid + 1, R, pos);
  }
}
int query(int Left, int Right, int L, int R, int l, int r) {
  if (l <= L && R <= r) return cnt[Right] - cnt[Left];
  int mid = L + R >> 1;
  int ret = 0;
  if (l <= mid) ret += query(lson[Left], lson[Right], L, mid, l, r);
  if (mid < r) ret += query(rson[Left], rson[Right], mid + 1, R, l, r);
  return ret;
}
int sx[maxn], sy[maxn], px[maxn], py[maxn], tx[maxn], ty[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &sx[i], &sy[i]);
    tx[i] = sx[i];
    ty[i] = sy[i];
  }
  sort(tx + 1, tx + 1 + n);
  sort(ty + 1, ty + 1 + n);
  vector<vector<int> > v(n + 1, vector<int>());
  int cx = n, cy = n;
  for (int i = 1; i <= n; i++) {
    px[i] = lower_bound(tx + 1, tx + 1 + cx, sx[i]) - tx;
    py[i] = lower_bound(ty + 1, ty + 1 + cy, sy[i]) - ty;
    v[px[i]].push_back(py[i]);
  }
  for (int i = 1; i <= n; i++) {
    T[i] = T[i - 1];
    for (auto &y : v[i]) insert(T[i], T[i], 1, cy, y);
  }
  int arr[10];
  for (int i = 1; i <= 9; i++) scanf("%d", &arr[i]);
  int pr[10];
  for (int i = 1; i <= 9; i++) pr[i] = i;
  do {
    int num[10];
    for (int i = 1; i <= 9; i++) num[i] = arr[pr[i]];
    int arr1 = num[1] + num[4] + num[7];
    int arr2 = num[2] + num[5] + num[8];
    double x1, x2;
    if (tx[arr1] != tx[arr1 + 1])
      x1 = (tx[arr1] + tx[arr1 + 1]) / 2.0;
    else
      continue;
    if (tx[arr1 + arr2] != tx[arr1 + arr2 + 1])
      x2 = (tx[arr1 + arr2] + tx[arr1 + arr2 + 1]) / 2.0;
    else
      continue;
    int arr3 = num[1] + num[2] + num[3];
    int arr4 = num[4] + num[5] + num[6];
    double y1, y2;
    if (ty[arr3] != ty[arr3 + 1])
      y1 = (ty[arr3] + ty[arr3 + 1]) / 2.0;
    else
      continue;
    if (ty[arr3 + arr4] != ty[arr3 + arr4 + 1])
      y2 = (ty[arr3 + arr4] + ty[arr3 + arr4 + 1]) / 2.0;
    else
      continue;
    if (num[1] != query(T[0], T[arr1], 1, n, 1, arr3)) continue;
    if (num[2] != query(T[arr1], T[arr1 + arr2], 1, n, 1, arr3)) continue;
    if (num[3] != query(T[arr1 + arr2], T[n], 1, n, 1, arr3)) continue;
    if (num[4] != query(T[0], T[arr1], 1, n, arr3 + 1, arr3 + arr4)) continue;
    if (num[5] != query(T[arr1], T[arr1 + arr2], 1, n, arr3 + 1, arr3 + arr4))
      continue;
    if (num[6] != query(T[arr1 + arr2 + 1], T[n], 1, n, arr3 + 1, arr3 + arr4))
      continue;
    if (num[7] != query(T[0], T[arr1], 1, n, arr3 + arr4 + 1, n)) continue;
    if (num[8] != query(T[arr1], T[arr1 + arr2], 1, n, arr3 + arr4 + 1, n))
      continue;
    if (num[9] != query(T[arr1 + arr2], T[n], 1, n, arr3 + arr4 + 1, n))
      continue;
    printf("%f %f\n%f %f\n", x1, x2, y1, y2);
    return 0;
  } while (next_permutation(pr + 1, pr + 10));
  puts("-1");
  return 0;
}
