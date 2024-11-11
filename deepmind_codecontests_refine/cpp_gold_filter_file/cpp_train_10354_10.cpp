#include <bits/stdc++.h>
using namespace std;
long long a[100003];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
  }
  long long energy = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (energy + a[i] - a[i + 1] < 0) {
      ans += abs(energy + a[i] - a[i + 1]);
      energy = 0;
    } else {
      energy = energy + a[i] - a[i + 1];
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
