#include <bits/stdc++.h>
using namespace std;
long int n;
long long int tree[200001 * 10];
long int a[200002];
void build(long int node, long int start, long int end) {
  if (start == end) {
    tree[node] = a[start];
  } else {
    long int mid = (start + end) / 2;
    build(2 * node + 1, start, mid);
    build(2 * node + 2, mid + 1, end);
    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
  }
}
void update(long int node, long int start, long int end, long int ind) {
  if (start == end)
    tree[node] = a[ind];
  else {
    long int mid = (start + end) / 2;
    if (start <= ind && ind <= mid) {
      update(2 * node + 1, start, mid, ind);
    } else {
      update(2 * node + 2, mid + 1, end, ind);
    }
    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
  }
}
long long int query(long int node, long int start, long int end, long int l,
                    long int r) {
  if (r < start || end < l) {
    return 0;
  }
  if (l <= start && end <= r) {
    return tree[node];
  }
  long int mid = (start + end) / 2;
  long long int p1 = query(2 * node + 1, start, mid, l, r);
  long long int p2 = query(2 * node + 2, mid + 1, end, l, r);
  return (p1 + p2);
}
long int idx[200002];
long int root(long int x) {
  while (idx[x] != x) {
    idx[x] = idx[idx[x]];
    x = idx[x];
  }
  return x;
}
int main() {
  cin >> n;
  long int ans = 0;
  for (long int i = 0; i <= n + 1; i++) a[i] = i, idx[i] = i;
  build(0, 0, n);
  long long int b[n];
  for (long int i = 0; i < n; i++) cin >> b[i];
  vector<long int> x;
  for (long int i = n - 1; i >= 0; i--) {
    long int l = 0, r = n - 1;
    long int ans = -1;
    while (l <= r) {
      long int mid = (l + r) / 2;
      long long int temp1 = query(0, 0, n - 1, 0, mid);
      if (temp1 == b[i]) {
        ans = mid + 1;
        break;
      } else if (temp1 < b[i]) {
        l = mid + 1;
      } else
        r = mid - 1;
    }
    ans = root(ans);
    x.push_back(ans);
    a[ans] = 0;
    update(0, 0, n, ans);
    idx[root(ans)] = root(ans + 1);
  }
  for (long int i = 0; i < x.size(); i++) cout << x[x.size() - 1 - i] << " ";
}
