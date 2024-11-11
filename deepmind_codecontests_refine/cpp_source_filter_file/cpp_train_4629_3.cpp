#include <bits/stdc++.h>
using namespace std;
int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, -1, 1, 1, -1, -1, 1};
int n;
void add(int i, int j) { printf("%d + %d = %d\n", i, j, i + j); }
void sub(int i, int j) { printf("%d - %d = %d\n", i, j, i - j); }
void mul(int i, int j) { printf("%d * %d = %lld\n", i, j, 1LL * i * j); }
void solve4() {
  mul(4, 2);
  mul(3, 1);
  mul(8, 3);
}
void solve5() {
  add(5, 1);
  sub(3, 2);
  mul(4, 1);
  mul(6, 4);
}
int o;
int main() {
  scanf("%d", &n);
  if (n < 4) {
    cout << "NO" << endl;
    return 0;
  }
  puts("YES");
  if (n == 4) {
    solve4();
    return 0;
  }
  if (n == 5) {
    solve5();
    return 0;
  }
  if (n & 1) {
    for (int i = 6; i <= n; i += 2) {
      sub(i + 1, i);
      o++;
    }
    o++;
    solve5();
    while (o--) {
      mul(24, 1);
    }
    return 0;
  }
  for (int i = 5; i <= n; i += 2) {
    sub(i + 1, i);
    o++;
  }
  solve4();
  while (o--) {
    mul(24, 1);
  }
  return 0;
}
