#include <bits/stdc++.h>
using namespace std;
int a[100069];
int sum[100069];
double odp[100069];
int main() {
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = n; i >= 1; i--) {
    sum[i]++;
    sum[a[i]] += sum[i];
  }
  odp[1] = 1;
  for (int i = 2; i <= n; i++) {
    odp[i] = odp[a[i]] + 1 + (0.5) * (sum[a[i]] - sum[i] - 1);
  }
  for (int i = 1; i <= n; i++) {
    printf("%.9f", odp[i]);
  }
}
