#include <bits/stdc++.h>
int n;
int ex[105];
int a, b;
int sum;
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) scanf("%d", &ex[i]);
  scanf("%d&d", &a, &b);
  for (int i = a; i < b; ++i) sum += ex[i];
  printf("%d", sum);
  return 0;
}
