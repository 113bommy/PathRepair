#include <bits/stdc++.h>
using namespace std;
int n, z[11], a[200005];
int getp(int idx) {
  int val = 0;
  for (int i = 0; i < 11; i++) {
    int t;
    if (idx == z[i]) continue;
    printf("? %d %d\n", idx, z[i]);
    fflush(stdout);
    scanf("%d", &t);
    if (t & (1 << i)) val += 1 << i;
  }
  return val;
}
void solve() {
  srand(time(0));
  scanf("%d", &n);
  int cnt = 0;
  memset(z, 0, sizeof(z));
  while (cnt < 11) {
    int x = rand() % (n - 1) + 2;
    int y = rand() % (x - 1) + 1;
    int t;
    printf("? %d %d\n", x, y);
    fflush(stdout);
    scanf("%d", &t);
    for (int i = 0; i < 11; i++) {
      if (!z[i] && !(t & (1 << i))) {
        z[i] = x;
        cnt++;
      }
    }
  }
  int idx = 1, val = getp(idx);
  for (int i = 2; i <= n && val; i++) {
    int t;
    printf("? %d %d\n", idx, i);
    fflush(stdout);
    scanf("%d", &t);
    if ((t & val) == val) {
      idx = i;
      val = getp(idx);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (idx == i)
      a[i] = val;
    else {
      int t;
      printf("? %d %d\n", idx, i);
      fflush(stdout);
      scanf("%d", &t);
      a[i] = t;
    }
  }
  printf("! ");
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
}
int main() {
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
