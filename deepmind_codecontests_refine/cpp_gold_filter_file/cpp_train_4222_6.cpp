#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long seg[6000005], n, x[1000005], y[1000005], arr[1000005];
void update(long long node, long long s, long long e, long long ind,
            long long val) {
  if (s == e) {
    seg[node] = val;
    return;
  }
  long long mid = s + (e - s) / 2;
  if (mid >= ind)
    update(node * 2, s, mid, ind, val);
  else
    update(node * 2 + 1, mid + 1, e, ind, val);
  seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
}
long long query(long long node, long long s, long long e, long long l,
                long long r) {
  if (r < s || l > e) return 0;
  if (s >= l && e <= r) return seg[node];
  long long mid = s + (e - s) / 2;
  return max(query(node * 2, s, mid, l, r),
             query(node * 2 + 1, mid + 1, e, l, r));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0, x; i < n; i++) cin >> x, y[x] = i;
  for (int i = 0; i < n; i++) arr[i] = y[x[i]];
  for (int i = 0; i < n; i++)
    update(1, 0, n - 1, arr[i], query(1, 0, n - 1, arr[i], n - 1) + 1);
  cout << seg[1];
  return 0;
}
