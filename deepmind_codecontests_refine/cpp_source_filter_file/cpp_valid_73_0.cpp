#include <bits/stdc++.h>
using namespace std;
long long t, n;
long long a[1010], ans = 0;
long long check() {
  for (long long i = 1; i <= n; i++)
    if (a[i] != i) return 0;
  return 1;
}
void swap(long long &a, long long &b) {
  long long w = a;
  a = b;
  b = w;
}
void f(long long x) {
  if (a[x] > a[x + 1]) swap(a[x], a[x + 1]);
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    ans = 0;
    if (check()) {
      cout << "0\n";
      continue;
    }
    while (1) {
      ans++;
      if (ans & 1)
        for (long long i = 1; i <= n - 2; i += 2) f(i);
      else
        for (long long i = 2; i <= n - 1; i++) f(i);
      if (check()) break;
    }
    cout << ans << endl;
  }
  return 0;
}
