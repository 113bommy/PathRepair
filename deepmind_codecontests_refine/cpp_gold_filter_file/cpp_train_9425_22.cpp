#include <bits/stdc++.h>
using namespace std;
int ar[100100];
char inp[100100];
int f() {
  int num = 0, neg = 0;
  if (inp[0] == '-') neg = 1;
  for (int i = neg; inp[i] != '\0'; i++) num = 10 * num + (inp[i] - '0');
  if (neg) num *= -1;
  return num;
}
int main() {
  int n, k;
  scanf("%d", &n);
  scanf("%d", &k);
  int cnt = 0;
  for (int i = 0; i <= n; i++) {
    scanf("%s", inp);
    if (inp[0] == '?') {
      ar[i] = (1e9);
      cnt++;
    } else
      ar[i] = f();
  }
  if (k == 0) {
    if (ar[0] != (1e9)) {
      if (ar[0] == 0)
        printf("Yes");
      else
        printf("No");
    } else {
      if ((n + 1 - cnt) % 2 == 1)
        printf("Yes");
      else
        printf("No");
    }
  } else {
    if (cnt == 0) {
      for (int i = 0; i < n; i++) {
        if (ar[i] % k) {
          printf("No");
          return 0;
        } else
          ar[i + 1] += (ar[i] / k);
      }
      if (ar[n] == 0)
        printf("Yes");
      else
        printf("No");
    } else {
      if ((n + 1) % 2 == 1)
        printf("No");
      else
        printf("Yes");
    }
  }
}
