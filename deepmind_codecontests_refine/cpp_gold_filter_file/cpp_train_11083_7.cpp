#include <bits/stdc++.h>
using namespace std;
long long int tree[400000] = {0};
long long int lazy[400000] = {0};
void update(long long int node, long long int a, long long int b,
            long long int i, long long int j, long long int val) {
  if (lazy[node] != 0) {
    tree[node] |= lazy[node];
    if (a != b) {
      lazy[2 * node] |= lazy[node];
      lazy[2 * node + 1] |= lazy[node];
    }
    lazy[node] = 0;
  }
  if (a > b || i > j || i > b || j < a) return;
  if (a >= i && j >= b) {
    tree[node] |= val;
    if (a != b) {
      lazy[2 * node] |= val;
      lazy[2 * node + 1] |= val;
    }
    return;
  }
  long long int mid = (a + b) / 2;
  update(2 * node, a, mid, i, j, val);
  update(2 * node + 1, mid + 1, b, i, j, val);
  tree[node] = (tree[2 * node] & tree[2 * node + 1]);
}
long long int query(long long int node, long long int a, long long int b,
                    long long int i, long long int j) {
  if (lazy[node] != 0) {
    tree[node] |= lazy[node];
    if (a != b) {
      lazy[2 * node] |= lazy[node];
      lazy[2 * node + 1] |= lazy[node];
    }
    lazy[node] = 0;
  }
  if (a >= i && j >= b) {
    return tree[node];
  }
  long long int mid = (a + b) / 2;
  if (j <= mid)
    return query(2 * node, a, mid, i, j);
  else if (i > mid)
    return query(2 * node + 1, mid + 1, b, i, j);
  else {
    long long int m1 = query(2 * node, a, mid, i, j);
    long long int m2 = query(2 * node + 1, mid + 1, b, i, j);
    return m1 & m2;
  }
}
int main(int argc, const char* argv[]) {
  long long int n, m, x, y, z;
  scanf("%I64d", &n);
  scanf("%I64d", &m);
  vector<pair<pair<long long int, long long int>, long long int> > a;
  for (long long int i = 0; i < m; i++) {
    scanf("%I64d", &x);
    scanf("%I64d", &y);
    scanf("%I64d", &z);
    x--;
    y--;
    a.push_back(pair<pair<long long int, long long int>, long long int>(
        pair<long long int, long long int>(x, y), z));
    update(1, 0, n - 1, x, y, z);
  }
  long long int flag = 0;
  for (long long int i = 0; i < m; i++) {
    if (query(1, 0, n - 1, a[i].first.first, a[i].first.second) !=
        a[i].second) {
      flag = 1;
      break;
    }
  }
  if (!flag) {
    printf("YES\n");
    for (int i = 0; i < n; i++) {
      printf("%lld ", query(1, 0, n - 1, i, i));
    }
  } else {
    printf("NO\n");
  }
  return 0;
}
