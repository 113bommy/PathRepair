#include <bits/stdc++.h>
using namespace std;
int n, a[100000], b[100000], c;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  b[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) b[i] = min(a[i], b[i + 1]);
  for (int i = 0; i < n - 1; i++)
    if (a[i] > b[i + 1]) c++;
  printf("%d\n", c);
  return 0;
}
