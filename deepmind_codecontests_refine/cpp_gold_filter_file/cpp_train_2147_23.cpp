#include <bits/stdc++.h>
using namespace std;
long long c[100010], old[100010];
int main() {
  long long k1, k2, k3, t1, t2, t3;
  int n;
  scanf("%I64d%I64d%I64d", &k1, &k2, &k3);
  scanf("%I64d%I64d%I64d", &t1, &t2, &t3);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &c[i]);
    old[i] = c[i];
  }
  long long res = 0;
  for (int i = k1; i < n; i++) {
    if (c[i] < c[i - k1] + t1) c[i] = c[i - k1] + t1;
  }
  for (int i = 0; i < n; i++) c[i] += t1;
  for (int i = k2; i < n; i++) {
    if (c[i] < c[i - k2] + t2) c[i] = c[i - k2] + t2;
  }
  for (int i = 0; i < n; i++) c[i] += t2;
  for (int i = k3; i < n; i++) {
    if (c[i] < c[i - k3] + t3) c[i] = c[i - k3] + t3;
  }
  for (int i = 0; i < n; i++) c[i] += t3;
  long long maxi = 0;
  for (int i = 0; i < n; i++) {
    if (c[i] - old[i] > maxi) maxi = c[i] - old[i];
  }
  printf("%I64d\n", maxi);
  return 0;
}
