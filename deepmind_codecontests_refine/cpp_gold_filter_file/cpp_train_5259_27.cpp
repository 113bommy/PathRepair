#include <bits/stdc++.h>
using namespace std;
const int M = 100100;
int A[M], pos[M];
int main() {
  int i, j, k, temp, maxx = 0, n;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
    pos[A[i]] = i;
  }
  temp = 1;
  maxx = 1;
  for (i = 2; i <= n; i++) {
    if (pos[i] > pos[i - 1]) {
      temp++;
      maxx = (((maxx) > (temp)) ? (maxx) : (temp));
    } else {
      temp = 1;
    }
  }
  printf("%d\n", n - maxx);
  return 0;
}
