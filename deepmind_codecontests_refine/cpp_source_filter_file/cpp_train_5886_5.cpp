#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  bool isPoss = true;
  int d[1000], z[1000], bf = 1000;
  for (int i = 0; i < n; i++) {
    scanf("%d", d + i);
    int now = -1;
    int digit[4] = {d[i] / 1000, (d[i] % 1000) / 100, (d[i] % 100) / 10,
                    d[i] % 10};
    if (d[i] % 1000 + 1000 >= bf)
      now = d[i] % 1000 + 1000;
    else if (d[i] % 1000 + 2000 >= bf && d[i] % 1000 + 2000 <= 2011)
      now = d[i] % 1000 + 2000;
    for (int k = 0; k < 10; k++) {
      int newD[3] = {digit[0] * 1000 + k * 100 + digit[2] * 10 + digit[3],
                     digit[0] * 1000 + digit[1] * 100 + k * 10 + digit[3],
                     digit[0] * 1000 + digit[1] * 100 + digit[2] * 10 + k};
      for (int j = 0; j < 3; j++) {
        if (newD[j] >= bf && newD[j] < now && newD[j] <= 2011) now = newD[j];
      }
    }
    if (now == -1) isPoss = false;
    z[i] = bf = now;
  }
  if (isPoss) {
    for (int i = 0; i < n; i++) printf("%d\n", z[i]);
  } else
    printf("No solution\n");
}
