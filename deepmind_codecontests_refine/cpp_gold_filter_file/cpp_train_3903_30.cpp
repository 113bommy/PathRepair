#include <bits/stdc++.h>
unsigned int get_index(char[]);
int main() {
  char lucky_number[11];
  unsigned int index;
  scanf("%s", lucky_number);
  index = get_index(lucky_number);
  printf("%u\n", index);
  return 0;
}
unsigned int get_index(char lucky_number[]) {
  short i;
  unsigned int index = 1;
  for (i = 0; lucky_number[i] != '\0'; i++) {
    if (lucky_number[i] == '4') {
      index = (index << 1);
    } else if (lucky_number[i] == '7') {
      index = (index << 1) + 1;
    }
  }
  index = index - 1;
  return index;
}
