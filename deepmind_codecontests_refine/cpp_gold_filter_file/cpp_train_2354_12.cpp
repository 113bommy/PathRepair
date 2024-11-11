#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f;
using namespace std;
int a[10000000];
int main() {
  int n;
  scanf("%d", &n);
  int num = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] % 2 == 0) num++;
  }
  if (num != n)
    printf("First\n");
  else
    printf("Second\n");
  return 0;
}
