#include <bits/stdc++.h>
using namespace std;
int q[1000005], p[1000005], tag[1000005];
int n;
int Max[1000005];
int MAX(int a, int b) { return a > b ? a : b; }
void Build(int l, int r, int id) {
  Max[id] = -1;
  if (l == r) return;
  int mid = (l + r) / 2;
  Build(l, mid, id + id);
  Build(mid + 1, r, id + id + 1);
}
int Query(int a, int b, int l, int r, int id) {
  int s = -1, t = -1;
  int ans;
  if (l >= a && b >= r) return Max[id];
  int mid = (l + r) / 2;
  if (a <= mid) s = Query(a, b, l, mid, id + id);
  if (b > mid) t = Query(a, b, mid + 1, r, id + id + 1);
  if (s != -1 && t != -1)
    ans = MAX(s, t);
  else if (s != -1)
    ans = s;
  else if (t != -1)
    ans = t;
  else
    ans = -1;
  return ans;
}
void Update(int u, int v, int l, int r, int id) {
  if (l == r) {
    if (Max[id] < v || Max[id] == -1) Max[id] = v;
    return;
  }
  int mid = (l + r) / 2;
  if (mid >= u)
    Update(u, v, l, mid, id + id);
  else
    Update(u, v, mid + 1, r, id + id + 1);
  if (Max[id + id] != -1 && Max[id + id + 1] != -1)
    Max[id] = MAX(Max[id + id], Max[id + id + 1]);
  else if (Max[id + id] != -1)
    Max[id] = Max[id + id];
  else if (Max[id + id + 1] != -1)
    Max[id] = Max[id + id + 1];
  else
    Max[id] = -1;
}
int main() {
  int i, j;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> q[i];
  for (i = 1; i <= n; i++) cin >> p[i];
  for (i = 1; i <= n; i++) tag[p[i]] = i;
  Build(1, n, 1);
  for (i = 1; i <= n; i++) {
    int pos = tag[q[i]];
    if (pos == n) {
      Update(pos, 1, 1, n, 1);
      continue;
    }
    int temp = Query(pos + 1, n, 1, n, 1);
    if (temp == -1)
      Update(pos, 1, 1, n, 1);
    else
      Update(pos, temp + 1, 1, n, 1);
  }
  cout << Query(1, n, 1, n, 1) << endl;
  return 0;
}
