#include <bits/stdc++.h>
using namespace std;
const int size = 205;
int a[size], n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < (n << 1); ++i) scanf("%d", &a[i]);
  int i, j, ans = 0;
  for (i = 0; i < (n << 1); i += 2) {
    for (j = i + 1; j < (n << 1); ++j) {
      if (a[j] == a[i]) break;
    }
    for (; j > (i + 1); --j) {
      swap(a[j], a[j - 1]);
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
