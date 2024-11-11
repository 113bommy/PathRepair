#include <bits/stdc++.h>
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
const double pi = acos(-1.0);
const long long mod = 1e9 + 7;
using namespace std;
int b[] = {4, 7, 47, 74, 447, 474, 477, 747, 774};
int a[1005];
int ok = 1;
int main() {
  memset(a, 0, sizeof(a));
  for (int i = 0; i < 9; i++) {
    for (int j = b[i]; j <= 1000; j += b[i]) {
      if (a[i] == 0) a[i] = 1;
    }
  }
  int n;
  scanf("%d", &n);
  if (a[n] == 1)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
