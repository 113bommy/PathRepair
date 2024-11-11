#include <bits/stdc++.h>
using namespace std;
int const N = 5e3 + 123;
int n, a[N], b[N];
int ans;
int p[N], ip[N];
int c[N];
int query(int i, int j) {
  printf("? %d %d\n", i, j);
  fflush(stdout);
  int resp;
  scanf("%d", &resp);
  return resp;
}
void solve() {
  for (int i = 0; i < n; ++i) a[i] = query(i, i);
  for (int i = 0; i < n; ++i) b[i] = query(i, (i + 1) % n);
  for (int i = 0; i < n; ++i) {
    p[0] = i;
    for (int j = 1; j < n; ++j) {
      p[j] = (p[j - 1] ^ a[j] ^ b[j - 1]);
    }
    for (int j = 0; j < n; ++j) ip[p[j]] = j;
    bool f = true;
    for (int j = 0; j < n; ++j) {
      if ((p[j] ^ ip[j]) != a[j]) f = false;
      if ((p[j] ^ ip[(j + 1) % n]) != b[j]) f = false;
    }
    if (f) {
      ++ans;
      for (int j = 0; j < n; ++j) {
        c[j] = p[j];
      }
    }
  }
}
int main() {
  scanf("%d", &n);
  solve();
  printf("!\n");
  printf("%d\n", ans);
  for (int i = 0; i < n; ++i) printf("%d ", c[i]);
  fflush(stdout);
  return 0;
}
