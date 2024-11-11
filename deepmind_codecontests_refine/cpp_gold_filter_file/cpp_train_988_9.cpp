#include <bits/stdc++.h>
using namespace std;
int n, m, bx, by;
int N1[20], N2[20];
long long base[20];
int main() {
  while (~scanf("%d%d", &n, &bx)) {
    base[0] = 1;
    for (int i = 1; i <= n - 1; i++) {
      base[i] = base[i - 1] * bx;
    }
    long long ans1 = 0;
    for (int i = 0; i <= n - 1; i++) {
      int num;
      scanf("%d", &num);
      ans1 += num * base[n - 1 - i];
    }
    scanf("%d", &m);
    scanf("%d", &by);
    base[0] = 1;
    for (int i = 1; i <= m - 1; i++) {
      base[i] = base[i - 1] * by;
    }
    long long ans2 = 0;
    for (int i = 0; i <= m - 1; i++) {
      int num;
      scanf("%d", &num);
      ans2 += num * base[m - 1 - i];
    }
    if (ans1 == ans2)
      puts("=");
    else if (ans1 < ans2)
      puts("<");
    else
      puts(">");
  }
}
