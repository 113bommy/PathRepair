#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum1, sum2;
  cin >> n;
  int a[100000], b[100000];
  int x[100000] = {0}, y[100000] = {0};
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    scanf("%d", &b[i]);
    x[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    sum1 = n - 1 + x[b[i]];
    sum2 = n - 1 - x[b[i]];
    printf("%d %d\n", sum1, sum2);
  }
  return 0;
}
