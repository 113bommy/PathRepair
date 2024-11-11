#include <bits/stdc++.h>
using namespace std;
char a[15][15], b[15][15], t[15][15];
int n;
void copy() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) t[i][j] = a[i][j];
}
int check() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (a[i][j] != b[i][j]) return 0;
  return 1;
}
void Upd() {
  copy();
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) a[i][j] = t[n - j - 1][i];
}
void put() {
  for (int i = 0; i < n; ++i, puts("")) printf("%s", a[i]);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%s", a[i]);
  for (int i = 0; i < n; ++i) scanf("%s", b[i]);
  for (int i = 0; i < 4; ++i) {
    if (check()) return puts("Yes"), 0;
    Upd();
  }
  copy();
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) a[i][j] = t[n - i - 1][j];
  for (int i = 0; i < 4; ++i) {
    if (check()) return puts("Yes"), 0;
    Upd();
  }
  copy();
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) a[i][j] = t[i][n - j - 1];
  for (int i = 0; i < 4; ++i) {
    if (check()) return puts("Yes"), 0;
    Upd();
  }
  return puts("No"), 0;
}
