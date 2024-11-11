#include <bits/stdc++.h>
int n, t, b, f;
int a[1000010], vi[1000010], tot;
int st[1000010];
void deal(int x) {
  while (tot && a[st[tot]] != x) {
    int y = st[tot];
    a[y] *= -1;
    tot--;
    deal(-a[y]);
  }
  if (!tot && x != -1) {
    puts("NO");
    exit(0);
  }
  tot--;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &b);
    vi[b] = 1;
  }
  tot = 0;
  for (int i = 0; i < n; i++) {
    if (vi[i]) {
      deal(a[i]);
      a[i] *= -1;
    } else {
      st[++tot] = i;
    }
  }
  deal(-1);
  puts("YES");
  for (int i = 0; i < n; i++) printf("%d ", a[i]);
  puts("");
}
