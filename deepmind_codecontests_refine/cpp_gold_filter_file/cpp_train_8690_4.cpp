#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  if (n % 2 == 0) {
    for (int i = 0; i < n / 2; i++) {
      if (i > 0) printf("%c", ' ');
      printf("%d ", i + 1);
      printf("%d", n - i);
    }
    printf("%c", '\n');
  } else {
    for (int i = 0; i < n / 2; i++) {
      if (i > 0) printf("%c", ' ');
      printf("%d ", i + 1);
      printf("%d", n - i);
    }
    printf("%c", ' ');
    printf("%d", n / 2 + 1);
    printf("%c", '\n');
  }
  return 0;
}
