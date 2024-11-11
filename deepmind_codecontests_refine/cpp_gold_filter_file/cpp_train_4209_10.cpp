#include <bits/stdc++.h>
using namespace std;
int T[110][3], Tt, Tk, a, b, dato, sum;
int main() {
  scanf("%d%d", &Tt, &Tk);
  a = Tt / Tk;
  while (a--) {
    for (b = 1; b <= Tk; b++) {
      scanf("%d", &dato);
      T[b][dato]++;
    }
  }
  for (b = 1; b <= Tk; b++) {
    if (T[b][1] != 0 and T[b][2] != 0) {
      if (T[b][1] < T[b][2])
        sum = sum + T[b][1];
      else
        sum = sum + T[b][2];
    }
  }
  printf("%d", sum);
}
