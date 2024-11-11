#include <bits/stdc++.h>
using namespace std;
void Gen(int n, int a[]) {
  if (n == 2)
    a[0] = 3, a[1] = 4;
  else if (n & 1) {
    for (int i = (0); i < (n - 2); i++) a[i] = 1;
    a[n - 2] = 2, a[n - 1] = n / 2 + 1;
  } else {
    for (int i = (0); i < (n - 1); i++) a[i] = 1;
    a[n - 1] = n / 2 - 1;
  }
}
int n, m;
int a[105], b[105];
int main() {
  scanf("%d%d", &n, &m);
  Gen(n, a);
  Gen(n, b);
  for (int i = (0); i < (n); i++)
    for (int j = (0); j < (m); j++) printf("%d ", a[i] * b[j]);
  return 0;
}
