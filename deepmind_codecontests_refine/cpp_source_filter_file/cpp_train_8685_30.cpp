#include <bits/stdc++.h>
using namespace std;
bool judge(int num) {
  int k = sqrt(num);
  if (k * k == num) return true;
  return false;
}
int main() {
  int n, m;
  while (scanf("%d %d", &n, &m) != EOF) {
    int a, b, c, d;
    int flag = 0;
    for (a = 1; a <= 20; a++)
      for (b = 1; b <= 20; b++)
        for (c = 1; c <= 20; c++)
          for (d = 1; d <= 20; d++)
            if (judge(a * a * (m - 1) + b * b) &&
                judge(a * a * (n - 1) + c * c) &&
                judge(c * c * (m - 1) + d * d) &&
                judge(b * b * (n - 1) + d * d))
              goto endw;
  endw:;
    for (int i = 1; i <= n - 1; i++) {
      for (int j = 1; j <= m - 1; j++) printf("%d ", a);
      printf("%d\n", b);
    }
    for (int i = 1; i <= m - 1; i++) printf("%d ", c);
    printf("%d\n", d);
  }
  return 0;
}
