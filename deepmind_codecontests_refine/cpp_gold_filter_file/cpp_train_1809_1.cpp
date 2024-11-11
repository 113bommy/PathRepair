#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
long long a[N], n, c[N], b[N];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = n - 1; i > 1; i--) {
    if (a[i] + a[i - 1] <= (a[i - 2] << 1)) {
      a[i - 1] += a[i];
    } else {
      if (a[i] >= a[i - 1]) {
        a[i - 1] = a[i] - a[i - 1];
        c[i - 1]++;
      } else {
        a[i - 1] = a[i - 1] - a[i];
        b[i]++;
      }
    }
  }
  if (a[0] > a[1])
    b[1]++;
  else
    c[0]++;
  int t = 0;
  for (int i = 0; i < n; i++) {
    t = t + b[i];
    printf("%s", (t + c[i]) & 1 ? "-" : "+");
  }
  return 0;
}
