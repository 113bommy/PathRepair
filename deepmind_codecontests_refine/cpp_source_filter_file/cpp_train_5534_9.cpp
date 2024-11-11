#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main() {
  int i, j;
  long long n, k;
  cin >> n >> k;
  a[0] = 99999999;
  long long sum = (k + 1) * k / 2;
  if (n < sum)
    cout << "NO";
  else {
    int t = (n - sum) / k;
    int yu = (n - sum) % k;
    int flag = 1;
    for (i = 1; i <= k; i++) {
      if (yu >= k - i + 1 && (t + 1 + i) < a[i - 1] * 2) {
        t++;
        yu -= k - i + 1;
      }
      a[i] = t + i;
    }
    if (yu) flag = 0;
    if (flag) {
      cout << "YES\n";
      for (i = 1; i <= k; i++) {
        if (i > 1) printf(" ");
        printf("%d", a[i]);
      }
    } else
      cout << "NO\n";
  }
  return 0;
}
