#include <bits/stdc++.h>
using namespace std;
void stop() {
  printf("press any key to continue...\n");
  while (getchar() != '\n') {
  }
}
int main() {
  for (int i = 0; i <= 9; i++) {
    printf("??%d>>%d??\n", i, i);
  }
  printf("??>>?\n");
  for (int i = 0; i <= 8; i++) {
    printf("%d?<>%d\n", i, i + 1);
  }
  printf("9?>>?0\n");
  printf("?<>1\n");
  printf(">>??\n");
}
