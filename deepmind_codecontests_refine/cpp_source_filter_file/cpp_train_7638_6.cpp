#include <bits/stdc++.h>
using namespace std;
long long a[10005];
int main() {
  long long n, m, d;
  cin >> n >> m >> d;
  for (int i = 0; i < n * m; i++) {
    int x;
    cin >> x;
    a[i] = x;
  }
  int k = a[0] % d;
  int flag = 0;
  for (int i = 0; i < n * m; i++) {
    if (a[i] % d != k) {
      flag = 1;
      break;
    }
  }
  if (flag) {
    cout << "-1";
    return 0;
  }
  sort(a, a + n);
  k = m * n;
  long long ans = 0;
  long long val = a[k / 2];
  for (int i = 0; i < k; i++) {
    ans += (abs(a[i] - val));
  }
  cout << ans / d;
  return 0;
}
