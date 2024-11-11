#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  char arr[1000001];
  scanf("%s", &arr);
  int digits[10] = {0};
  scanf("%d", &arr);
  int len = strlen(arr);
  for (int i = 0; i < len; ++i) {
    digits[arr[i] - 48]++;
  }
  char rem[7][5] = {"1869", "6198", "1896", "1689", "1986", "1968", "1698"};
  int num_rem = 0;
  digits[1]--;
  digits[6]--;
  digits[8]--;
  digits[9]--;
  for (int i = 1; i < 10; ++i) {
    for (int j = 0; j < digits[i]; ++j) {
      printf("%c\n", (char)(i + 48));
      num_rem = (num_rem + i) % 7;
    }
  }
  printf("%s", rem[num_rem]);
  for (int i = 0; i < digits[0]; ++i) {
    printf("0");
  }
  return 0;
}
