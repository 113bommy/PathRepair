#include <bits/stdc++.h>
using namespace std;
char que;
int ctos, dif;
int main() {
  scanf("%d%d", &ctos, &dif);
  if (dif > ctos or (dif == 1 and ctos > 1)) {
    printf("-1\n");
  } else {
    if (ctos == 1 and dif == 1) {
      printf("a\n");
      return 0;
    }
    for (int i = 1; i <= ctos - dif + 2; i++) {
      if (i % 2 == 1) {
        printf("a");
      } else {
        printf("b");
      }
    }
    for (int i = 3; i <= dif; i++) {
      que = 'a' + i - 1;
      printf("%c", que);
    }
    printf("\n");
  }
  return 0;
}
