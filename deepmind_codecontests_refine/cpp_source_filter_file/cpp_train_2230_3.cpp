#include <bits/stdc++.h>
using namespace std;
int zero[400444];
int num[400044];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &num[i]);
  memset(zero, 0, sizeof(zero));
  ;
  for (int i = n - 1; i >= 0; i--) zero[i] = zero[i + 1] + (num[i] == 0);
  long long sum = 0;
  for (int i = 0; i < n; i++)
    if (num[i] == 1) sum += zero[i];
  printf("%d\n", sum);
}
