#include <bits/stdc++.h>
using namespace std;
set<long long> s;
set<long long>::iterator it;
vector<long long> v;
int n, m;
long long tree[500005];
long long a[100004];
long long int power(long long int x, long long int y) {
  long long int res = 1;
  x = x;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
void build(int node, int x, int y, int state) {
  if (x > y) return;
  if (x == y) {
    tree[node] = a[x];
    return;
  }
  int mid = (x + y) / 2;
  build(2 * node + 1, x, mid, (state + 1) % 2);
  build(2 * node + 2, mid + 1, y, (state + 1) % 2);
  if (state == 0) {
    tree[node] = tree[2 * node + 1] | tree[2 * node + 2];
  } else {
    tree[node] = tree[2 * node + 1] ^ tree[2 * node + 2];
  }
}
void update(int node, int x, int y, int index, long long val, int state) {
  if (x > y) return;
  if (x == y && x == index) {
    a[index] = val;
    tree[node] = a[index];
    return;
  }
  int mid = (x + y) / 2;
  if (index <= mid)
    update(2 * node + 1, x, mid, index, val, (state + 1) % 2);
  else
    update(2 * node + 2, mid + 1, y, index, val, (state + 1) % 2);
  if (state == 0) {
    tree[node] = tree[2 * node + 1] | tree[2 * node + 2];
  } else {
    tree[node] = tree[2 * node + 1] ^ tree[2 * node + 2];
  }
}
int main() {
  int i, j, t;
  ;
  scanf("%d", &n);
  ;
  ;
  scanf("%d", &m);
  ;
  int total = power(2, n);
  for (i = 1; i <= total; i++) scanf("%lld", &a[i]);
  build(0, 1, total, (n & 1) ^ 1);
  for (i = 1; i <= m; i++) {
    int x;
    long long y;
    scanf("%d %lld", &x, &y);
    update(0, 1, total, x, y, (n & 1) ^ 1);
    long long ans = tree[0];
    printf("%lld\n", ans);
  }
  return 0;
}
