#include <bits/stdc++.h>
struct shik {
  int A;
  int B;
  int num;
} data[1000];
int tmp[10], itmp[10], appear[10];
int main() {
  int n, i, flag, ans, a, b, c, d, check, cA, cB, k, j;
  ans = -1;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d%d%d", &data[i].num, &data[i].A, &data[i].B);
  flag = 0;
  for (i = 0; i < 10000; i++) {
    for (j = 0; j < 10; j++) appear[j] = -1;
    a = itmp[0] = i / 1000;
    b = itmp[1] = (i / 100) % 10;
    c = itmp[2] = (i / 10) % 10;
    d = itmp[3] = i % 10;
    appear[itmp[0]] = 0;
    appear[itmp[1]] = 1;
    appear[itmp[2]] = 2;
    appear[itmp[3]] = 3;
    if (a == b || a == c || a == d || b == c || b == d || c == d) continue;
    check = 0;
    for (j = 0; j < n; j++) {
      cA = 0;
      cB = 0;
      tmp[0] = data[j].num / 1000;
      tmp[1] = (data[j].num / 100) % 10;
      tmp[2] = (data[j].num / 10) % 10;
      tmp[3] = data[j].num % 10;
      for (k = 0; k < 4; k++) {
        if (appear[tmp[k]] != -1) {
          if (appear[tmp[k]] == k)
            cA++;
          else
            cB++;
        }
      }
      if (cA == data[j].A && cB == data[j].B)
        check++;
      else
        break;
    }
    if (check == n) {
      if (flag == 0) {
        flag = 1;
        ans = i;
      } else {
        flag = 2;
      }
    }
  }
  if (flag == 0)
    printf("Incorrect data\n");
  else if (flag == 1)
    printf("%d\n", ans);
  else if (flag == 2)
    printf("Need more data\n");
  return 0;
}
