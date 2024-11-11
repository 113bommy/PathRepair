#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  scanf("%d", &N);
  int mas[110];
  for (int i = 0; i < N; i++) {
    scanf("%d", &mas[i]);
  }
  int sol = 0;
  for (int i = 0; i < N; i++) {
    if (mas[i] > sol) sol = mas[i];
  }
  for (int k = 0; k < N; k++) {
    int xor_s = mas[k];
    for (int i = k + 1; i < N; i++) {
      xor_s = xor_s ^ mas[i];
      if (xor_s > sol) sol = xor_s;
    }
  }
  printf("%d\n", sol);
  return 0;
}
