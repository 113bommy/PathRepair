#include <bits/stdc++.h>
using namespace std;
int a[2000000], n, *s = a;
int min(int x) { return x < n ? x : n; }
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) a[i] = 1 + i;
  for (int k = 2; k <= n; ++k, ++s)
    for (int u = (n - 1) / k * k; u >= 0; u -= k) s[min(u + k)] = s[u];
  for (int i = 0; i < n; ++i) cout << s[i];
}
