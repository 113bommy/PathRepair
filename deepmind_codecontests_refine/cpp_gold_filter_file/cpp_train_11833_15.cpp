#include <bits/stdc++.h>
using namespace std;
int n;
char a[22][22], b[22][22], c[22][22];
bool chk() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (a[i][j] != b[i][j]) return false;
  return true;
}
void flip() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n - j - 1; j++) swap(a[i][j], a[i][n - j - 1]);
}
void rotate() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) c[j][n - i - 1] = a[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) a[i][j] = c[i][j];
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%s", a[i]);
  for (int i = 0; i < n; i++) scanf("%s", b[i]);
  bool f = false;
  for (int i = 0; i < 2 && !f; i++) {
    for (int j = 0; j < 4 && !f; j++) {
      if (chk()) f = true;
      rotate();
    }
    flip();
  }
  puts(f ? "Yes" : "No");
  return 0;
}
