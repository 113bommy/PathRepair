#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
int n;
int cur[MAXN], goal[MAXN], tot, lastedge[MAXN], nextedge[MAXN];
int fa[MAXN], so[MAXN];
int ans[MAXN];
int cnt;
bool fliped[MAXN], entered[MAXN];
void addedge(int a, int b) {
  tot++;
  so[tot] = b;
  nextedge[tot] = lastedge[a];
  lastedge[a] = tot;
}
void Xor(int k, int t) {
  int tmp = lastedge[k];
  while (tmp) {
    if (!(t & 1)) {
      cur[so[tmp]] = !cur[so[tmp]];
    }
    Xor(so[tmp], t + 1);
    tmp = nextedge[tmp];
  }
}
void Deal(int k) {
  entered[k] = true;
  if (fa[fa[k]] != fa[k] && fliped[fa[fa[k]]]) {
    cur[k] = !cur[k];
    fliped[k] = !fliped[k];
  }
  if (cur[k] != goal[k]) {
    ans[cnt++] = k;
    fliped[k] = !fliped[k];
  }
  int tmp = lastedge[k];
  while (tmp) {
    if (!entered[so[tmp]]) {
      fa[so[tmp]] = k;
      Deal(so[tmp]);
    }
    tmp = nextedge[tmp];
  }
  return;
}
void init() {
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
}
int main() {
  scanf("%d", &n);
  init();
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    addedge(b, a);
    addedge(a, b);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &cur[i + 1]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &goal[i + 1]);
  }
  Deal(1);
  printf("%d\n", cnt);
  for (int i = 0; i < cnt; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
