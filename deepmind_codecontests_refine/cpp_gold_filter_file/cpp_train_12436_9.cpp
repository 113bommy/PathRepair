#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int pat[N], str[N];
int f[N];
int n, w;
int a[N], b[N];
int PF(int len, int c) {
  while (len && pat[len] != c) len = f[len - 1];
  if (pat[len] == c) len++;
  return len;
}
void computeF() {
  f[0] = 0;
  int len = 0;
  for (int i = 1; i < w - 1; i++) {
    len = PF(len, pat[i]);
    f[i] = len;
  }
}
int match() {
  int len = 0, ret = 0;
  for (int i = 0; i < n - 1; i++) {
    len = PF(len, str[i]);
    if (len == w - 1) ret++, len = f[len - 1];
  }
  return ret;
}
int main() {
  scanf("%d%d", &n, &w);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < w; i++) scanf("%d", &b[i]);
  if (w == 1) {
    printf("%d\n", n);
    return 0;
  }
  for (int i = 0; i < n - 1; i++) str[i] = a[i] - a[i + 1];
  for (int i = 0; i < w - 1; i++) pat[i] = b[i] - b[i + 1];
  computeF();
  printf("%d\n", match());
  return 0;
}
