#include <bits/stdc++.h>
using namespace std;
int a[333333];
int f[333333];
int main() {
  int n;
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int t = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] >= f[t])
      f[++t] = a[i];
    else {
      int idx = lower_bound(f + 1, f + t + 1, a[i]) - f;
      f[idx] = a[i];
    }
  }
  cout << t;
  return 0;
}
