#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  cin >> n >> m;
  long long int a[n], i, j, k, l, cnt = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long int maxx = a[n - 1] + m, minn;
  for (i = n - 2; i >= 0; i--) {
    cnt = cnt + a[n - 1] - a[i];
  }
  if (cnt >= m) {
    cout << a[n - 1] << " " << maxx;
    return 0;
  } else {
    if ((m - cnt) % n != 0)
      minn = a[n - 1] + ((m - cnt) / n) + 1;
    else
      minn = a[n - 1] + ((m - cnt) / n);
    cout << minn << " " << maxx;
  }
}
