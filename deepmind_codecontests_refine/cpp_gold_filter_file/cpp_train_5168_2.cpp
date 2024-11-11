#include <bits/stdc++.h>
int main() {
  int nol;
  scanf("%d", &nol);
  int min = 1000000000;
  int number[100001];
  for (int i = 0; i < nol; i++) {
    scanf("%d", &number[i]);
    if (number[i] < min) {
      min = number[i];
    }
  }
  int tampung[100001];
  int a = 0;
  for (int i = 0; i < nol; i++) {
    if (number[i] == min) {
      tampung[a] = i;
      a++;
    }
  }
  min = 1000000000;
  for (int j = 0; j < a - 1; j++) {
    if (tampung[j + 1] - tampung[j] < min) {
      min = tampung[j + 1] - tampung[j];
    }
  }
  printf("%d\n", min);
  return 0;
}
