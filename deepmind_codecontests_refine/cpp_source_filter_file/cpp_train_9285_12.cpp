#include <bits/stdc++.h>
using namespace std;
int n, a[10010];
long long sum, sum2;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), sum += a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n / 2; i++) sum2 += a[i];
  cout << (sum - sum2) * (sum - sum2) + sum2 * sum2;
}
