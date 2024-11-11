#include <bits/stdc++.h>
using namespace std;
int n;
int cal(int x) { return sqrt(1ll * n * n - 1ll * x * x); }
long long ans = 0;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int res = cal(i) - cal(i + 1);
    if (res == 0)
      ans += (i == 0 ? 2 : 4);
    else
      ans += (i == 0 ? 2 : 4) * res;
  }
  cout << (n == 0 ? 1 : ans + 2);
}
