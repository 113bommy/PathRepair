#include <bits/stdc++.h>
using namespace std;
unsigned long long modulo(long long a, long long b, long long n) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y) % n;
    }
    y = (y * y) % n;
    b /= 2;
  }
  return x % n;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  ;
  int n, k;
  cin >> n >> k;
  int a[n + 1];
  int b[n + 1];
  int mx = -1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  for (int i = 1; i <= n; i++) {
    int it = i;
    while (it >= 1 && it <= n) {
      a[it] = 0;
      it = it - k;
    }
    it = i;
    while (it < n) {
      a[it] = 0;
      it = it + k;
    }
    int e = 0, s = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] == 1)
        e++;
      else if (a[i] == -1)
        s++;
    }
    for (int i = 1; i <= n; i++) a[i] = b[i];
    mx = max(abs(e - s), mx);
  }
  cout << mx << '\n';
  return 0;
}
