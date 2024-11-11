#include <bits/stdc++.h>
using namespace std;
long long flag, cnt, j, i, k, ans, maxy;
long long n;
int main() {
  cin >> n;
  vector<long long> v(n), temp(n), ans(n);
  ans[n - 1] = 0;
  maxy = v[n - 1];
  for (i = 0; i < n; i++) {
    cin >> v[i];
    temp[i] = v[i];
  }
  for (i = n - 2; i >= 0; i--) {
    if (maxy <= v[i]) maxy = v[i + 1];
    ans[i] = maxy - v[i] + 1;
    if (ans[i] < 0) ans[i] = 0;
  }
  for (i = 0; i < n; i++) cout << ans[i] << " ";
}
