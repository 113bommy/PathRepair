#include <bits/stdc++.h>
using namespace std;
const int maxval = 1e6 + 6;
int b[maxval];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    b[a] = a;
  }
  for (int i = 0; i < maxval; i++)
    if (!b[i]) b[i] = b[i - 1];
  int ans = 0;
  for (int i = 2; i < maxval; i++) {
    if (b[i] == i) {
      for (int j = i - 1; j < maxval; j += i) {
        if (j < maxval && i <= b[j] && ans < b[j] % i) ans = b[j] % i;
      }
    }
  }
  printf("%d", ans);
  return 0;
}
