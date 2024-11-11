#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, kk;
  cin >> n >> kk;
  char t[n];
  cin >> t;
  char arr[n * kk], sub[n];
  int i = 0, c, j = 0;
  for (i = 0; i < n; i++) arr[i] = t[i];
  i = 1;
  c = 1;
  while (1) {
    int k = 0, p = 1;
    while (i + k < n) {
      if (arr[i + k] == t[k]) {
        k++;
        continue;
      } else {
        p = 0;
        break;
      }
    }
    if (p == 0) {
      i++;
      continue;
    }
    if (p == 1) {
      while (k < n) {
        sub[j] = t[k];
        j++;
        k++;
      }
      break;
    }
  }
  cout << arr;
  int y;
  for (c = 2; c <= kk; c++)
    for (y = 0; y < j; y++) cout << sub[y];
  return 0;
}
