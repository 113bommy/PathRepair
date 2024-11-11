#include <bits/stdc++.h>
using namespace std;
int R[20] = {0};
int M[20] = {0};
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (n); i++) {
    scanf("%d", &M[i]);
  }
  for (int i = 0; i < (n); i++) {
    scanf("%d", &R[i]);
  }
  int ans = 0;
  for (int i = (0); i <= (720720); i++) {
    for (int j = 0; j < (n); j++) {
      if (i % M[j] == R[j]) {
        ans++;
        break;
      }
    }
  }
  printf("%.10lf\n", (double)ans / (n + 1));
  return 0;
}
