#include <bits/stdc++.h>
int arr[200];
int main() {
  int jmlstick = 0;
  int stick = 0;
  int hasil = 0;
  scanf("%d", &jmlstick);
  for (int i = 1; i <= jmlstick; i++) {
    scanf("%d", &stick);
    arr[stick]++;
  }
  for (int i = 1; i < jmlstick; i++) {
    hasil += (arr[i] / 2);
  }
  printf("%d\n", hasil / 2);
  return 0;
}
