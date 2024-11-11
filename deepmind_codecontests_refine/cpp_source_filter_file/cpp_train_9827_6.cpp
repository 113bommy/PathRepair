#include <bits/stdc++.h>
using namespace std;
long long a[2000010];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  sort(a + 1, a + n + 1);
  long long sum = 0;
  for (int i = n; i >= 1; i /= 4)
    for (int j = n; j >= i; j--) sum += a[j];
  printf("%I64d", sum);
}
