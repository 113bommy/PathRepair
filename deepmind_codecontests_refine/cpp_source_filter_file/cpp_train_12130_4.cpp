#include <bits/stdc++.h>
using namespace std;
struct node {
  int a, b;
  bool operator<(const node &A) const { return a < A.a; }
} p[100010];
int cnt[100010];
int n;
int find(int x, int r) {
  int l = 0;
  while (l < r - 1) {
    int mid = (l + r) / 2;
    if (x < p[mid].a)
      r = mid;
    else
      l = mid;
  }
  return l;
}
int main(int argc, char const *argv[]) {
  scanf("%d", &n);
  p[0].a = -1;
  for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].a, &p[i].b);
  sort(p + 1, p + n + 1);
  memset(cnt, 0, sizeof(cnt));
  cnt[1] = 1;
  int M = 0;
  for (int i = 2; i <= n; i++) {
    int pos = find(p[i].a - p[i].b - 1, i);
    cnt[i] = cnt[pos] + 1;
    M = max(M, cnt[i]);
  }
  printf("%d\n", n - M);
  return 0;
}
