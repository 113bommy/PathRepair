#include <bits/stdc++.h>
using namespace std;
int a[100500];
int z[200500];
int main() {
  int n;
  cin >> n;
  long long int m;
  int w;
  cin >> m >> w;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int l = *min_element(a, a + n);
  int r = 1000010001;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    long long int res = 0;
    int now = 0;
    for (int i = 0; i <= n + n; i++) {
      z[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      now -= z[i];
      if (mid <= a[i] + now) {
        continue;
      } else {
        int e = mid - a[i] - now;
        now += e;
        res += e;
        z[i + w] += e;
      }
    }
    if (res > m) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << l;
  return 0;
}
