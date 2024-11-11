#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int ask(int i, int j) {
  printf("? %d %d\n", i, j);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
}
int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  vector<int> a(n + 1);
  int x = ask(1, 2), y = ask(1, 3), z = ask(2, 3);
  a[1] = ((x + y) - z) / 2;
  a[2] = x - a[1];
  a[3] = y - a[1];
  for (int i = 4; i <= n; ++i) {
    a[i] = ask(1, i) - a[1];
  }
  printf("! ");
  fflush(stdout);
  for (int i = 1; i <= n; ++i) {
    printf("%d ", a[i]);
    fflush(stdout);
  }
  return 0;
}
