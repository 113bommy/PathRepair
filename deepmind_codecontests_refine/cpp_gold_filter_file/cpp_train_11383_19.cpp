#include <bits/stdc++.h>
using namespace std;
int n;
long long int a[200000];
long long int sd[20];
long long int ans = 0;
int main() {
  cin >> n;
  sd[0] = 1;
  for (int i = 1; i < 16; i++) sd[i] = sd[i - 1] * 2;
  int c;
  for (int i = 1; i < n; i++) {
    scanf("%I64d", &c);
    ans += a[i] + c;
    int t = 1;
    while (2 * t + i <= n) t *= 2;
    if (t + i <= n) a[t + i] += a[i] + c;
    printf("%I64d\n", ans);
  }
  return 0;
}
