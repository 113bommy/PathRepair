#include <bits/stdc++.h>
using namespace std;
const int maxint = -1u >> 1;
const int maxn = 300;
const int r = 300;
int n;
int a[10];
int f[maxn];
void init() {
  memset(f, -1, sizeof(f));
  int dir = 0;
  for (int i = 0; i + dir < r; ++i) {
    if (f[i] >= 0) continue;
    f[i] = i + dir;
    f[i + dir] = i;
    ++dir;
  }
}
bool win() {
  if (n == 1) return a[0];
  if (n == 2) {
    if (f[a[0]] >= 0 && f[a[0]] != a[1]) return true;
    if (f[a[1]] >= 0 && f[a[1]] != a[0]) return true;
    for (int i = 1; i <= min(a[0], a[1]); ++i) {
      if (f[a[0] - i] == a[1] - i) return true;
    }
    return false;
  }
  return a[0] ^ a[1] ^ a[2];
}
int main() {
  init();
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; ++i) {
      if (i < n) scanf("%d", &a[i]);
    }
    bool ok = win();
    if (ok)
      printf("BitLGM\n");
    else
      printf("BitAryo\n");
  }
  return 0;
}
