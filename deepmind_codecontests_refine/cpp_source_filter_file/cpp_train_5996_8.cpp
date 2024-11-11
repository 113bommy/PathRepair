#include <bits/stdc++.h>
using namespace std;
int numbers[110];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int cursor = 1;
  for (int i = 0; i < k; i++) {
    int tmp;
    scanf("%d", &tmp);
    tmp %= n - k;
    while (tmp--) {
      while (true) {
        cursor += 1;
        cursor %= n;
        if (numbers[cursor] == 0) {
          break;
        }
      }
    }
    numbers[cursor] = 1;
    if (cursor == 0) {
      cursor = n;
    }
    printf("%d ", cursor);
    while (true) {
      cursor += 1;
      cursor %= n;
      if (numbers[cursor] == 0) {
        break;
      }
    }
  }
  printf("\n");
  return 0;
}
