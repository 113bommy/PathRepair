#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
long long const inf = 1e18;
int const mxn = 5e3 + 10;
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
int l[mxn];
set<int> s;
int bmm(int a, int b) {
  if (b == 0)
    return a;
  else
    return bmm(b, a % b);
}
int f(int x) {
  if (x == 1) return 0;
  for (int i = 2; i * i < x; i++) {
    if (x % i == 0) {
      if (s.find(i) == s.end()) {
        return (f(x / i) + 1);
      } else
        return (f(x / i) - 1);
    }
  }
  if (s.find(x) == s.end())
    return 1;
  else
    return -1;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> l[i];
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    s.insert(a);
  }
  for (int t = n; t >= 1; t--) {
    int g = l[1];
    for (int i = 1; i <= t; i++) {
      g = bmm(g, l[i]);
    }
    if (f(g) < 0) {
      for (int i = 1; i <= t; i++) l[i] = l[i] / g;
    }
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += f(l[i]);
  }
  cout << sum;
}
