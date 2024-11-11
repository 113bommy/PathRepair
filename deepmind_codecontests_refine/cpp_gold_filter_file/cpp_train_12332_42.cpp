#include <bits/stdc++.h>
int tshirts(int num, int size[]) {
  int i;
  if (size[num] > 0) {
    size[num]--;
    return num;
  } else {
    for (i = 1; i < 5; i++) {
      if (num + i < 5 && size[num + i] > 0) {
        size[num + i]--;
        return num + i;
      } else if (num - i >= 0 && size[num - i] > 0) {
        size[num - i]--;
        return num - i;
      }
    }
  }
}
void print_res(int num) {
  if (num == 0)
    printf("S\n");
  else if (num == 1)
    printf("M\n");
  else if (num == 2)
    printf("L\n");
  else if (num == 3)
    printf("XL\n");
  else if (num == 4)
    printf("XXL\n");
}
int main(void) {
  int size[5], k, i, j, flag, num;
  char buf;
  for (i = 0; i < 5; i++) scanf("%d", &size[i]);
  scanf("%d", &k);
  for (i = 0; i < k; i++) {
    flag = 0;
    while (1) {
      scanf("%c", &buf);
      if (flag == 0) {
        if (buf == 'S') {
          num = tshirts(0, size);
          break;
        } else if (buf == 'M') {
          num = tshirts(1, size);
          break;
        } else if (buf == 'L') {
          num = tshirts(2, size);
          break;
        } else if (buf == 'X') {
          flag = 1;
        }
      } else {
        if (buf == 'L') {
          num = tshirts(3, size);
          break;
        } else if (buf == 'X') {
          scanf("%c", &buf);
          num = tshirts(4, size);
          break;
        }
      }
    }
    print_res(num);
  }
  return 0;
}
