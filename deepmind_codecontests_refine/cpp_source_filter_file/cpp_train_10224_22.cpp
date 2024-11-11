#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200005];
int indices[200005];
int pre[200005];
int arr[200005];
bool cmp(int x, int y) { return a[x] > a[y] || (a[x] == a[y] && x < y); }
long long rquery(int v) {
  long long ans = 0;
  while (v) {
    ans += arr[v];
    v -= ((v) & (-(v)));
  }
  return ans;
}
void modify(int loc, long long val) {
  while (loc <= n) {
    arr[loc] += val;
    loc += ((loc) & (-(loc)));
  }
}
long long query(int l, int r) { return rquery(r) - rquery(l - 1); }
struct Query {
  int k, pos, id;
};
Query queries[200005];
int answers[200005];
bool cmp2(Query x, Query y) { return x.k < y.k; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    indices[i] = i;
  }
  sort(indices + 1, indices + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    if (a[indices[i]] != a[indices[i - 1]]) {
      pre[i] = i;
    } else {
      pre[i] = pre[i - 1];
    }
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int k, pos;
    scanf("%d%d", &k, &pos);
    queries[i].k = k;
    queries[i].pos = pos;
    queries[i].id = i;
  }
  sort(queries + 1, queries + n + 1, cmp2);
  int nextindex = 1;
  for (int i = 1; i <= m; i++) {
    while (nextindex <= queries[i].k) {
      modify(indices[nextindex], 1);
      nextindex++;
    }
    int l = 1, r = n;
    while (l < r) {
      int mid = (l + r) / 2;
      if (query(1, mid) < queries[i].pos) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    answers[queries[i].id] = a[l];
  }
  for (int i = 1; i <= m; i++) {
    printf("%d\n", answers[i]);
  }
  return 0;
}
