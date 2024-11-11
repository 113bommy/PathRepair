#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int vis[N];
int n;
bool flag;
void out(int a, int b) {
  if (!flag) {
    printf("%d %d\n", a, b);
    return;
  }
  if (vis[a] || vis[b]) {
    printf("%d %d\n", a, b);
    return;
  }
  vis[a] = 1, vis[b] = 1;
  printf("%d %d\n", a, n);
  printf("%d %d\n", b, n);
  printf("%d %d\n", a, b);
}
void inter_opt(int p) {
  out(p + 1, p + 2);
  out(p + 3, p + 4);
  out(p + 1, p + 3);
  out(p + 2, p + 4);
  out(p + 1, p + 4);
  out(p + 2, p + 3);
}
void ex(int a, int b) {
  out(a + 1, b + 1);
  out(a + 1, b + 2);
  out(a + 1, b + 3);
  out(a + 2, b + 1);
  out(a + 2, b + 4);
  out(a + 1, b + 4);
  out(a + 2, b + 3);
  out(a + 3, b + 1);
  out(a + 4, b + 2);
  out(a + 3, b + 2);
  out(a + 2, b + 2);
  out(a + 3, b + 3);
  out(a + 4, b + 1);
  out(a + 4, b + 4);
  out(a + 3, b + 4);
  out(a + 4, b + 3);
}
int main() {
  scanf("%d", &n);
  if (n % 4 == 2 || n % 4 == 3) {
    printf("NO\n");
    return 0;
  } else if (n % 4 == 1)
    flag = true;
  printf("YES\n");
  for (int k = 0; k < n / 4; k++) {
    inter_opt(4 * k);
  }
  for (int i = 0; i < n / 4; i++)
    for (int j = 0; j < i; j++) ex(4 * j, 4 * i);
  return 0;
}
