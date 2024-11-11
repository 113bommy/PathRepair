#include <bits/stdc++.h>
using namespace std;
const int seed = 131;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int n;
int a[maxn], b[maxn];
int f[maxn];
int Rank[maxn];
void init() {
  for (int i = 1; i <= n; i++) {
    f[i] = i;
    Rank[i] = 0;
  }
}
int getf(int v) { return v == f[v] ? v : (f[v] = getf(f[v])); }
long long sum[maxn];
void Merge(int n, int v) {
  int t1 = getf(n);
  int t2 = getf(v);
  if (Rank[t1] < Rank[t2]) {
    f[t1] = t2;
    sum[t2] += sum[t1];
  } else {
    f[t2] = t1;
    sum[t1] += sum[t2];
  }
  if (Rank[t1] == Rank[t2]) Rank[t1]++;
}
int vis[maxn];
long long ans[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum[i] = a[i];
  }
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  init();
  long long tmp = 0;
  for (int i = n; i >= 1; i--) {
    ans[i] = tmp;
    vis[b[i]] = 1;
    if (b[i] != n && vis[b[i] + 1]) Merge(b[i], b[i] + 1);
    if (b[i] != n && vis[b[i] - 1]) Merge(b[i], b[i] - 1);
    tmp = max(tmp, sum[getf(b[i])]);
  }
  for (int i = 1; i <= n; i++) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}
