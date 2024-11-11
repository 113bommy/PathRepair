#include <bits/stdc++.h>
using namespace std;
int b[101] = {0};
int main() {
  int i, j = 100, a, c = 0, f = 0, n;
  scanf("%d", &n);
  ;
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    b[a]++;
    if (b[a] == 4) {
      f++;
      b[a] = 0;
    }
  }
  sort(b, b + 100);
  while (b[j] > 1 && j >= 0) {
    c++;
    j--;
  }
  f += c / 2;
  printf("%d ", f);
  return 0;
}
