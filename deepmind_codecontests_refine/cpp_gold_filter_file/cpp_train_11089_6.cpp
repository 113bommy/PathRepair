#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int N = 1e5 + 10;
char ch[N];
int f[N], g[N];
int n;
void init() {
  scanf("%s", ch + 1);
  n = strlen(ch + 1);
  for (int i = 1; i <= n; i++) f[i] = ch[i] - '0', g[i] = f[i];
}
bool check(int l) {
  for (int i = l, j = n; i < j; i++, j--) {
    if (f[i] == f[j]) continue;
    if (i == j - 1) {
      if (f[i] - 1 == f[j] + 10) {
        f[i]--;
        f[j] += 10;
        continue;
      }
      return false;
    }
    if (f[i] - 1 == f[j]) {
      f[i]--;
      f[i + 1] += 10;
      continue;
    }
    if (f[i] == f[j] + 10) {
      f[j] += 10;
      f[j - 1]--;
      continue;
    }
    if (f[i] - 1 == f[j] + 10) {
      f[i]--;
      f[i + 1] += 10;
      f[j] += 10;
      f[j - 1]--;
      continue;
    }
    return false;
  }
  for (int i = l, j = n; i <= j; i++, j--) {
    if (f[i] < 0 || f[i] > 18 || f[i] != f[j]) return false;
    if (i == j) {
      if (f[i] % 2 != 0) return false;
      f[i] >>= 1;
    } else {
      f[j] >>= 1;
      f[i] -= f[j];
    }
  }
  if (f[1] == 0) return false;
  for (int i = l; i <= n; i++) printf("%d", f[i]);
  printf("\n");
  return true;
}
void work() {
  if (!check(1)) {
    for (int i = 1; i <= n; i++) f[i] = g[i];
    if (f[1] == 1 && n > 1) {
      f[2] += 10;
      if (check(2)) {
        return;
      }
    }
    puts("0");
  }
}
int main() {
  init();
  work();
  return 0;
}
