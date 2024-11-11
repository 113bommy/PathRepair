#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 6;
int a[N], n;
int main() {
  scanf("%d", &n);
  int a = 0, b = 0;
  for (int i = 0, u; i < n; ++i) {
    scanf("%d", &u);
    if (u == 2) {
      b++;
    } else {
      a++;
    }
  }
  if (b) {
    printf("2 ");
    b--;
  }
  if (a) {
    printf("1 ");
    a--;
  }
  while (a >= 2) {
    printf("1 1 ");
    a -= 2;
  }
  while (b) {
    printf("2 ");
    b--;
  }
  if (a) {
    printf("1 ");
  }
  return 0;
}
