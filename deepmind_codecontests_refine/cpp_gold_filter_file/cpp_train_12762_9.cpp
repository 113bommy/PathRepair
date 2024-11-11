#include <bits/stdc++.h>
using namespace std;
int ns[4][400010];
int cnt[4];
int cur[4];
int n, m;
long long p[400010];
bool used[400010];
bool cmp(int a, int b) {
  if (p[a] == p[b]) return a < b;
  return p[a] < p[b];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &p[i]);
  for (int i = 1; i <= n; i++) {
    int val;
    scanf("%d", &val);
    ns[val][cnt[val]++] = i;
  }
  for (int i = 1; i <= n; i++) {
    int val;
    scanf("%d", &val);
    ns[val][cnt[val]++] = i;
  }
  for (int i = 1; i <= 3; i++) sort(ns[i], ns[i] + cnt[i], cmp);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int cr;
    scanf("%d", &cr);
    bool ok = false;
    while (cur[cr] < cnt[cr]) {
      if (!used[ns[cr][cur[cr]]]) {
        used[ns[cr][cur[cr]]] = true;
        printf("%lld ", p[ns[cr][cur[cr]++]]);
        ok = true;
        break;
      }
      cur[cr]++;
    }
    if (!ok) printf("-1 ");
  }
  return 0;
}
