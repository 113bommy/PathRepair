#include <bits/stdc++.h>
using namespace std;
int main() {
  char ch, t;
  int p = 0;
  int A[2];
  A[0] = A[1] = 0;
  int n;
  vector<char> B;
  while (1) {
    scanf("%c%c", &ch, &t);
    if (ch == '=') {
      scanf("%d", &n);
      break;
    } else if (ch == '?')
      A[p]++;
    else if (ch == '+') {
      p = 0;
      B.push_back(ch);
    } else if (ch == '-') {
      p = 1;
      B.push_back(ch);
    }
  }
  int a = A[0] - A[1];
  int d = (n - a) / A[0];
  int temp = n - a;
  a = ceil((1.0 * (n - a)) / A[0]);
  if ((a < n) && (A[0] - A[1] <= n)) {
    printf("Possible\n");
    int Q[2];
    Q[1] = Q[0] = d + 1;
    int tt = (temp) - (d * A[0]);
    d++;
    int z = B.size();
    if (tt) {
      printf("%d ", d + 1);
      tt--;
    } else
      printf("%d ", d);
    for (int i = 0; i < z; i++) {
      printf("%c ", B[i]);
      if (B[i] == '-')
        printf("1 ");
      else {
        if (tt) {
          printf("%d ", d + 1);
          tt--;
        } else
          printf("%d ", d);
      }
    }
    printf("= %d\n", n);
  } else if (A[0] >= A[1]) {
    int x = A[0] - A[1];
    int m = (x - n) / A[1];
    int r = ((x - n) % A[1]) ? 1 : 0;
    if (r + m < n) {
      printf("Possible\n");
      m++;
      r = (x - n) % A[1];
      int z = B.size();
      printf("%d ", 1);
      for (int i = 0; i < z; i++) {
        printf("%c ", B[i]);
        if (B[i] == '+')
          printf("1 ");
        else {
          if (r) {
            printf("%d ", m + 1);
            r--;
          } else
            printf("%d ", m);
        }
      }
      printf("= %d\n", n);
    } else
      printf("Impossible\n");
  } else
    printf("Impossible\n");
  return 0;
}
