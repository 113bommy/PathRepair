#include <bits/stdc++.h>
using namespace std;
bool mark[1000];
int main() {
  int a;
  scanf("%d", &a);
  int k = 0;
  for (int i = 2; i <= a; i++) {
    if (!mark[i]) {
      bool pierwsza = true;
      for (int j = 2; j < i; j++) {
        if (i % j == 0) {
          pierwsza = false;
          break;
        }
      }
      if (pierwsza) {
        for (int j = i; j <= a; j *= i) {
          mark[j] = true;
          k++;
        }
      }
    }
  }
  printf("%d\n", k);
  for (int i = 0; i <= a; i++) {
    if (mark[i]) {
      printf("%d ", i);
    }
  }
  printf("\n");
  return 0;
}
