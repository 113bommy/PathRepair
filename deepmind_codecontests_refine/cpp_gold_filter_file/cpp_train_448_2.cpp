#include <bits/stdc++.h>
using namespace std;
int n, ar[100005];
int poww(int a) {
  int pangkat = 0;
  while (a + pow(2, pangkat + 1) <= n) {
    pangkat++;
  }
  return pow(2, pangkat) + a;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &ar[i]);
  long long cnt = 0;
  for (int i = 1; i <= n - 1; i++) {
    ar[poww(i)] += ar[i];
    cnt += ar[i];
    ar[i] = 0;
    printf("%I64d\n", cnt);
  }
  return 0;
}
