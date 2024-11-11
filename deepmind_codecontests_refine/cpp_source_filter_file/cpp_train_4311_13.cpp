#include <bits/stdc++.h>
using namespace std;
int main() {
  char name[1050];
  int A[100];
  int c, n, k, num, v;
  scanf("%s", name);
  scanf("%d", &n);
  fill(A, A + 27, 0);
  for (int(i) = 0; (i) < (strlen(name)); (i)++) {
    A[int(name[i] - 'a')]++;
  }
  c = 0;
  for (int(i) = 0; (i) < (26); (i)++)
    if (A[i] > 0) c++;
  if (c > n)
    printf("-1\n");
  else {
    for (int(k) = (1); (k) <= (n); (k)++) {
      v = 0;
      for (int(i) = 0; (i) < (26); (i)++) v += ceil((float)A[i] / k);
      if (v <= n) {
        num = k;
        break;
      }
    }
    printf("%d\n", num);
    c = 0;
    for (int(i) = 0; (i) < (26); (i)++) {
      for (int(j) = 0; (j) < (int(ceil((float)A[i] / num))); (j)++)
        printf("%c", 'a' + i), c++;
    }
    for (int(i) = 0; (i) < (max(0, n - c)); (i)++) printf("%c", 'a');
    printf("\n");
  }
  return 0;
}
