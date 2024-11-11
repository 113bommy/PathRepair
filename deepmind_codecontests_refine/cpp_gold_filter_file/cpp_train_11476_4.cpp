#include <bits/stdc++.h>
using namespace std;
int arr[200010];
int r[200010];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  for (int i = 0; i < n; i++) r[i] = arr[i] % m;
  sort(r, r + n);
  bool flag = false;
  for (int i = 0; i < n - 1; i++)
    if (r[i] == r[i + 1]) flag = true;
  if (flag)
    printf("0");
  else {
    long long int ans = 1;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        ans *= abs(arr[i] - arr[j]);
        ans = ans % m;
      }
    }
    printf("%lld", ans);
  }
}
