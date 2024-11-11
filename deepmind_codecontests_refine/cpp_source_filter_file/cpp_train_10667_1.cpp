#include <bits/stdc++.h>
using namespace std;
int n, t;
int p[512];
bool a[512][512];
char s[512];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    --p[i];
  }
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    for (int j = 0; j < n; ++j) {
      if (s[j] == '1') a[i][j] = 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        if (a[i][k] && a[j][k] && !a[i][j]) {
          a[i][j] = 1;
          a[j][i] = 1;
        }
      }
    }
  }
  for (int i = 0; i < n - 1; ++i) {
    int mp = p[i];
    int mi = i;
    for (int j = i + 1; j < n; ++j) {
      if (mp > p[j] && a[i][j]) {
        mp = p[j];
        mi = j;
      }
    }
    if (mi != i) {
      int t = p[i];
      p[i] = p[mi];
      p[mi] = t;
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d ", p[i] + 1);
  }
  printf("\n");
  return 0;
}
