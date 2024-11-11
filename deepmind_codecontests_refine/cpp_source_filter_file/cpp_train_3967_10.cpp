#include <bits/stdc++.h>
using namespace std;
const int maxn = 1200;
int main() {
  int n, m;
  while (scanf("%d %d", &n, &m) != EOF) {
    for (int i = 1; i <= maxn; i++) printf("9");
    for (int i = 1; i < maxn; i++) printf("0");
    printf("1");
    printf("\n");
    for (int i = 1; i <= maxn; i++) printf("9");
    printf("\n");
  }
  return 0;
}
