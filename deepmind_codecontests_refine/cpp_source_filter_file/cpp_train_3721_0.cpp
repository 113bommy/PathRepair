#include <bits/stdc++.h>
using namespace std;
int Count = 0;
int n = 0;
int N;
int val[1 << 4];
void bust(int pos) {
  if (pos == n) {
    int st = 1;
    int Val = 0;
    for (int i = n - 1; i >= 0; i--) {
      Val += val[i] * st;
      st *= 10;
    }
    if (Val <= N) Count++;
  } else {
    for (int i = 0; i < 2; i++) {
      if (pos == 0) {
        if (i == 1) {
          val[pos] = i;
          bust(pos + 1);
        }
      } else {
        val[pos] = i;
        bust(pos + 1);
      }
    }
  }
}
void GO() {
  for (int i = 1; i <= 9; i++) {
    n = i;
    bust(0);
  }
}
int main() {
  scanf("%d", &N);
  GO();
  printf("%d\n", Count);
  return 0;
}
