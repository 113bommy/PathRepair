#include <bits/stdc++.h>
using namespace std;
struct node {
  long long pre[5];
};
node tree[4 * 1000005];
int in[1000005], arr[1000005];
int n, k, i;
long long cnt[5];
void query(int nod, int s, int e, int i, int j) {
  if (s > j || e < i) return;
  if (s >= i && e <= j) {
    for (int i = 1; i <= 3; i++) cnt[i] = cnt[i] + tree[nod].pre[i];
    return;
  }
  int mid = (s + e) / 2, l = 2 * nod, r = l + 1;
  query(l, s, mid, i, j);
  query(r, mid + 1, e, i, j);
}
void update(int nod, int s, int e, int i) {
  if (s > i || e < i) return;
  if (s == e) {
    tree[nod].pre[1] += 1;
    for (int i = 1; i < 3; i++) tree[nod].pre[i + 1] += cnt[i];
    return;
  }
  int mid = (s + e) / 2, l = 2 * nod, r = l + 1;
  update(l, s, mid, i);
  update(r, mid + 1, e, i);
  for (int i = 1; i <= 3; i++)
    tree[nod].pre[i] = tree[l].pre[i] + tree[r].pre[i];
}
int main() {
  scanf("%d", &n);
  int tt = k;
  for (i = 1; i <= n; i++) {
    scanf("%d", &in[i]);
    arr[i] = in[i];
  }
  map<int, int> mp;
  int k = 1;
  sort(arr + 1, arr + n + 1);
  for (i = 1; i <= n; i++) {
    mp[arr[i]] = i;
  }
  for (i = n; i >= 1; i--) {
    memset(cnt, 0, sizeof cnt);
    query(1, 1, n, 1, mp[in[i]] - 1);
    update(1, 1, n, mp[in[i]]);
  }
  printf("%I64d\n", tree[1].pre[3]);
  return 0;
}
