#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const long long INF = 9999999999;
long long a[maxn];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    long long sum = 0;
    long long tem = 0;
    long long count1 = 0;
    for (int i = 0; i < n; i++) {
      scanf("%I64d", &a[i]);
    }
    sort(a, a + n);
    long long num_min = INF;
    for (int i = 0; i < n - 1; i++) {
      sum = abs(a[i] - a[i + 1]);
      if (sum < num_min) num_min = sum;
    }
    for (int i = 0; i < n - 1; i++) {
      tem = abs(a[i] - a[i + 1]);
      if (tem == num_min) count1++;
    }
    printf("%I64d %I64d\n", num_min, count1);
  }
  return 0;
}
