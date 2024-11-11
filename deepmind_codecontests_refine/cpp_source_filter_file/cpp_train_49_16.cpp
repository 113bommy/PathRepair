#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int total;
char ans1[105] = {"abs((abs((abs((abs((abs((abs(((32+33)-abs(((t+t)-"},
     ans2[105] = {"))))-32))-16))-8))-4))-2))-1"};
int x[105], y[105];
void work(int *a) {
  for (int i = 1; i < total; i++) printf("(");
  for (int i = 0; i < total; i++) {
    printf("(%s", ans1);
    printf("(%d+%d)", i, i);
    printf("%s)*(t", ans2);
    int k = a[i] / 2 - i;
    if (k >= 0) printf("+");
    printf("%d)", k);
    printf(")");
    if (i != 0) printf(")");
    if (i < total - 1) printf("+");
  }
  printf("\n");
}
int main() {
  int k1 = 0;
  for (int i = 0; ans1[i]; i++)
    if (ans1[i] == '(') k1++;
  int k2 = 0;
  for (int i = 0; ans2[i]; i++)
    if (ans2[i] == ')') k2++;
  scanf("%d", &total);
  for (int i = 0; i < total; i++) {
    int r;
    scanf("%d%d%d", x + i, y + i, &r);
  }
  work(x);
  work(y);
  return 0;
}
