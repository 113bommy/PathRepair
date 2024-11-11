#include <bits/stdc++.h>
using namespace std;
int f(char a[], char b[]) {
  int diff = 0;
  for (int i = 0; i < 6; ++i) diff += (a[i] != b[i]);
  return (int)ceil(diff / 2.0) - 1;
}
int main() {
  int n;
  scanf("%d", &n);
  char str[n][6];
  for (int i = 0; i < n; ++i) scanf("%s", str[i]);
  int ans = 3;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int temp = f(str[i], str[j]);
      ans = (temp < ans ? temp : ans);
    }
  }
  printf("%d", ans);
  return 0;
}
