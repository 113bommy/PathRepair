#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, k, l;
  bool fini = true;
  int fibo[43];
  fibo[0] = 1;
  fibo[1] = 2;
  for (i = 2; i < 43; i++) {
    fibo[i] = fibo[i - 1] + fibo[i - 2];
  }
  cin >> n;
  for (i = 0; i < 43 && fini; i++) {
    for (j = 0; j < 43 && fini; j++) {
      for (k = 0; k < 43 && fini; k++) {
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
