#include <bits/stdc++.h>
using namespace std;
long long x[10];
int main() {
  int n;
  scanf("%d", &n);
  x[0] = 1;
  for (int i = 1; i <= 9; i++) x[i] = x[i - 1] * 10;
  long long ans = 0;
  for (int i = 1; i <= 9; i++) {
    if (n >= x[i - 1]) ans += min((x[i] - x[i - 1]), n - x[i - 1] + 1) * i;
  }
  if (n == 1000000000) ans++;
  cout << ans << endl;
}
