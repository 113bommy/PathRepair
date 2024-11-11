#include <bits/stdc++.h>
using namespace std;
long long tong[int(2e3 + 100)], hieu[int(2e3 + 100)];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    tong[x + y + 1000]++;
    hieu[x - y + 1000]++;
  }
  long long res = 0;
  for (int i = (0); i <= (2100); i++) {
    if (tong[i] > 0) res += (tong[i] * (tong[i] - 1)) / 2;
    if (hieu[i] > 0) res += (hieu[i] * (hieu[i] - 1)) / 2;
  }
  printf("%I64d", res);
}
