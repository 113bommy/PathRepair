#include <bits/stdc++.h>
using namespace std;
int n;
int a[10 + 10000];
int d[5];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    d[a[i] % 3]++;
  }
  printf("%d\n", d[0] / 2 + min(d[2], d[1]));
  return 0;
}
