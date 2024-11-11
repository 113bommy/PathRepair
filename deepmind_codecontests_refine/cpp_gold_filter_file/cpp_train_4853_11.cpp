#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << "\n";
  err(++it, args...);
}
const long long N = 2e5 + 5, M = 1e9 + 7, inf = 1e18;
long long a[N], u[N], v[N], b[N], c[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  ;
  for (int i = 1; i < n; i++) {
    a[i] += a[i - 1];
  }
  for (int i = 0; i < n + 1; i++)
    for (int j = i; j < n + 1; j++) {
      long long s1 = 0, s2 = 0;
      if (i - 1 >= 0) s1 = a[i - 1];
      if (j - 1 >= 0) s2 = a[j - 1];
      if (i - 1 >= 0) s2 -= a[i - 1];
      if (s1 - s2 > u[j]) {
        u[j] = s1 - s2;
        b[j] = i;
      }
    }
  for (int i = 0; i < n + 1; i++)
    for (int j = i; j < n + 1; j++) {
      long long s1 = 0, s2 = 0;
      if (j - 1 >= 0) s1 = a[j - 1];
      if (i - 1 >= 0) s1 -= a[i - 1];
      if (n - 1 >= 0) s2 = a[n - 1];
      if (j - 1 >= 0) s2 -= a[j - 1];
      if (s1 - s2 > v[i]) {
        v[i] = s1 - s2;
        c[i] = j;
      }
    }
  long long ans = 0, x = 0, y = 0, z = 0;
  for (int i = 0; i < n + 1; i++) {
    if (u[i] + v[i] > ans) {
      ans = u[i] + v[i];
      x = b[i];
      y = i;
      z = c[i];
    }
  }
  cout << x << " " << y << " " << z << "\n";
}
