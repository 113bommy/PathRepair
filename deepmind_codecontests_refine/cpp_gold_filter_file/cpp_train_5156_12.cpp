#include <bits/stdc++.h>
using namespace std;
int main() {
  int num[5], num2[5];
  for (int i = 0; i < 5; i++) scanf("%1d", &num2[i]);
  num[0] = num2[0];
  num[1] = num2[2];
  num[2] = num2[4];
  num[3] = num2[3];
  num[4] = num2[1];
  int factor = 1;
  long long ori = 0;
  for (int i = 4; i >= 0; i--) {
    ori += (long long)num[i] * factor;
    factor *= 10;
  }
  long long temp = 1;
  for (int i = 0; i < 5; i++) {
    temp *= ori;
    temp %= 100000;
  }
  printf("%05d", temp);
}
