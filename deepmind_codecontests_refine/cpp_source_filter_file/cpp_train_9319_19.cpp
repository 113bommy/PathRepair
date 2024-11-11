#include <bits/stdc++.h>
using namespace std;
long long f(long long *ar, long long l, long long r) {
  long long s = 0;
  for (int i = l; i <= r; i++) s = s | ar[i];
  return s;
}
int main() {
  int n;
  cin >> n;
  long long a[1005];
  long long b[1005];
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  long long mx = 0;
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      long long s = f(a, i, j) + f(b, i, j);
      if (s > mx) mx = s;
    }
  }
  cout << mx << endl;
}
