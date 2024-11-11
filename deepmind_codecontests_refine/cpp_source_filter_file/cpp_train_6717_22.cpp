#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a[60];
  a[1] = 2;
  for (int i = 2; i <= 55; i++) a[i] = a[i - 1] * 2;
  for (int i = 2; i <= 55; i++) a[i] += a[i - 1];
  int n;
  while (~scanf("%d", &n)) {
    printf("%d\n", a[n]);
  }
}
