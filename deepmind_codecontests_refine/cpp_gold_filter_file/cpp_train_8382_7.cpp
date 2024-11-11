#include <bits/stdc++.h>
using namespace std;
int n, m, edgenum, head[1201010], vet[1201010], jie[1201010];
int a[1201010], id[1201010];
long long ans = 0;
set<int> now;
void add(int u, int v) {
  edgenum++;
  vet[edgenum] = v;
  jie[edgenum] = head[u];
  head[u] = edgenum;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    id[a[i]] = i;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > y) swap(x, y);
    add(x, i);
    add(y, i);
  }
  int tail = 1;
  now.clear();
  for (int i = 1; i <= n; i++) {
    int e = head[a[i]];
    tail = max(i, tail);
    while (e > 0) {
      int v = vet[e];
      now.insert(v);
      e = jie[e];
    }
    int flag = 1;
    while (flag && tail < n) {
      int u = a[tail + 1];
      e = head[u];
      while (e > 0) {
        int v = vet[e];
        if (now.find(v) != now.end()) {
          flag = 0;
          break;
        }
        e = jie[e];
      }
      if (flag == 1) {
        tail++;
        u = a[tail];
        e = head[u];
        while (e > 0) {
          int v = vet[e];
          now.insert(v);
          e = jie[e];
        }
      }
    }
    ans += tail - i + 1;
    e = head[a[i]];
    while (e > 0) {
      int v = vet[e];
      now.erase(v);
      e = jie[e];
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
