#include <bits/stdc++.h>
int main() {
  int n;
  std::cin >> n;
  int sum[3];
  sum[0] = 0;
  sum[1] = 0;
  sum[2] = 0;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    std::cin >> a >> b >> c;
    sum[0] = sum[0] + a;
    sum[1] = sum[1] + b;
    sum[2] = sum[2] + c;
  }
  if (sum[0] == 0 && sum[1] == 0 && sum[2] == 0)
    printf("YES");
  else
    printf("NO");
  return 0;
}
