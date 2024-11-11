#include <bits/stdc++.h>
int main(void) {
  int N;
  int num[2] = {};
  int result = 0;
  char temp[101];
  scanf("%d", &N);
  scanf("%s", temp);
  for (int i = 0; i < N; i++) {
    if (temp[i] == '8')
      num[0]++;
    else
      num[1]++;
  }
  while (num[0] >= 1 && num[0] + num[1] >= 11) {
    num[0]--;
    if (num[1] >= 10)
      num[1] -= 10;
    else {
      num[0] -= num[1];
      num[1] = 0;
    }
    result++;
  }
  printf("%d\n", result);
  return 0;
}
