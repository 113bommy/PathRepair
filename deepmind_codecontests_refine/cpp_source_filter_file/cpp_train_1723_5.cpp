#include <bits/stdc++.h>
using namespace std;
int n;
long long ct[3000010];
long long num[3000010];
int m;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    ct[a]++;
  }
  for (int i = 1; i * i < 3000010; i++) {
    for (int j = i; i * j < 3000010; j++) {
      if (i == j)
        num[i * j] += ct[i] * (ct[i] - 1);
      else
        num[i * j] += 2 * ct[i] * ct[j];
    }
  }
  for (int i = 3000010 - 2; i > 0; i--) num[i] += num[i + 1];
  long long x = n * (n - 1) - num[1];
  scanf("%d", &m);
  while (m--) {
    int a;
    scanf("%d", &a);
    printf("%I64d\n", num[a] + x);
  }
}
