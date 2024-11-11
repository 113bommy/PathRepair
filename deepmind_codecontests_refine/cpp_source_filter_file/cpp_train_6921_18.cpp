#include <bits/stdc++.h>
using namespace std;
const int maxn = int(1e5) + 52;
int n;
long long a[maxn], sum;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("I64", a + i);
  sort(a + 1, a + n + 1);
  sum = a[1];
  int j = 1;
  for (int i = 2; i <= n; i++)
    if (sum <= a[i]) sum += a[i], j++;
  printf("%d\n", j);
}
