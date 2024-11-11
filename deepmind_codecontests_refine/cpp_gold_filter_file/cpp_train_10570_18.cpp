#include <bits/stdc++.h>
using namespace std;
int n;
long long len[100010];
int cmp(long long a, long long b) { return a > b; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &len[i]);
  }
  sort(len + 1, len + n + 1);
  long long sum = 0;
  for (int i = 1; i < n; i++) {
    sum += len[i];
  }
  long long ans = len[n] - sum + 1;
  printf("%I64d\n", ans);
  return 0;
}
