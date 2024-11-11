#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, k, l;
  bool fini = true;
  int fibo[45];
  fibo[0] = 0;
  fibo[1] = 1;
  for (i = 2; i < 45; i++) {
    fibo[i] = fibo[i - 1] + fibo[i - 2];
  }
  cin >> n;
  for (i = 0; i < 45 && fini; i++) {
    for (j = 0; j < 45 && fini; j++) {
      for (k = 0; k < 45 && fini; k++) {
        if (n == fibo[i] + fibo[j] + fibo[k]) {
          printf("%d %d %d", fibo[i], fibo[j], fibo[k]);
          fini = false;
        }
      }
    }
  }
  if (fini) printf("I'm too stupid to solve this problem");
  return 0;
}
