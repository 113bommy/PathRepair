#include <bits/stdc++.h>
using namespace std;
int pri[10000], vis[100100];
int p;
int phi(int a) {
  int b = a;
  for (int i = 1; i <= p; i++) {
    if (b % pri[i] == 0) {
      a = a / pri[i] * (pri[i] - 1);
      while (b % pri[i] == 0) b /= pri[i];
    }
  }
  if (b > 1) {
    a = a / b * (b - 1);
  }
  return a;
}
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  if (b = 2 && a == 1) {
    printf("No\n");
    return 0;
  }
  if (b > 0 && a - (b - 1) >= 0 && (a - (b - 1)) % 2 == 0) {
    printf("Yes\n");
  } else
    printf("No\n");
  return 0;
}
