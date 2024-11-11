#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, i, j, ans, temp, f;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    long long int arr[n];
    for (i = 0; i < n; i++) scanf("%lld", &arr[i]);
    bool st[n];
    for (i = 0; i < n; i++) st[i] = 0;
    f = 1;
    for (i = 0; i < n; i++) {
      temp = i + arr[i];
      if (temp >= 0) {
        temp = temp % n;
        if (st[temp] == 1) {
          f = 0;
          break;
        }
        st[temp] = 1;
      } else {
        temp = (n - (abs(temp) % n)) % n;
        if (st[temp] == 1) {
          f = 0;
          break;
        }
        st[temp] = 1;
      }
    }
    if (f == 1)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
