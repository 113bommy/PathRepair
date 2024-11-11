#include <bits/stdc++.h>
long long a[100005];
using namespace std;
int main() {
  int n;
  long long maxV = -10000;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
    maxV = max(a[i], maxV);
  }
  long long len = 1;
  long long res = 1;
  for (int i = 2; i <= n; ++i) {
    if (a[i] == maxV && a[i] == a[i - 1]) {
      len++;
    } else
      len = 1;
    res = max(res, len);
  }
  cout << res;
  return 0;
}
