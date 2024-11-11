#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2)
    return (power(a, b - 1) * a);
  else {
    long long t = power(a, b / 2);
    return (t * t);
  }
}
bool prime(int a) {
  if (a == 2) return true;
  for (int i = 2; i * i <= a; ++i)
    if (a % i == 0) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    bool x, y;
    x = y = 0;
    bool ok = 1;
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i])
        if (b[i] - a[i] > 0 && !x)
          ok = 0;
        else if (b[i] - a[i] < 0 && !y)
          ok = 0;
      if (a[i] > 0) x = 1;
      if (a[i] < 0) y = 1;
    }
    if (ok)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
