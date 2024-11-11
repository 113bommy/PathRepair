#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long m;
  cin >> n >> m;
  long long ans = 0;
  vector<long> a(n);
  for (int i = 0; i < n; i++) {
    long x, y;
    cin >> x >> y;
    ans += x;
    a[i] = x - y;
  }
  sort(a.rbegin(), a.rend());
  for (int i = 0; i < n; i++) {
    if (i == 0 && m >= ans) {
      cout << i;
      return 0;
    }
    if (ans > m) {
      ans -= a[i];
    }
    if (ans <= m) {
      cout << i + 1;
      return 0;
    }
  }
  cout << "-1";
  return 0;
}
