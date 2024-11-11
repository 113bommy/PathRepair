#include <bits/stdc++.h>
using namespace std;
int cont[1009], a[1009], b[10050];
void fun() {
  for (int i = 2; i * i <= 1000 + 1; i++) {
    if (cont[i] == 0) {
      for (int j = 2; i * j <= 1000 + 1; j++) {
        cont[i * j] = 1;
      }
    }
  }
}
int main() {
  fun();
  int n, l = 1;
  scanf("%d", &n);
  if (n == 1) {
    printf("0");
  } else {
    for (int j = 2; j <= 33; j++) {
      for (int i = 2; i <= 10; i++) {
        if (cont[j] != 0) {
          break;
        }
        int num = powl(j, i);
        if (num > 1000) {
          break;
        }
        b[num] = 1;
      }
    }
    for (int i = 2; i <= n; i++) {
      if (cont[i] == 0 || b[i] == 1) {
        a[l] = i;
        l++;
        continue;
      }
    }
    printf("%d\n", l - 1);
    for (int i = 1; i < l; i++) {
      printf("%d ", a[i]);
    }
  }
  return 0;
}
