#include <bits/stdc++.h>
using namespace std;
int b[1000031];
int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  for (long long i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[a[i]]++;
  }
  int ans = 0;
  for (int i = 0; i < 1000031; i++) {
    if (b[i] % 2) ans++;
    b[i + 1] += b[i] / 2;
  }
  printf("%d\n", ans);
  return 0;
}
