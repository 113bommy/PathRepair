#include <bits/stdc++.h>
using namespace std;
const long long maxn = 500010;
const long long INF = 2147483647;
long long n, a[maxn], l, r;
char c[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  l = 0;
  r = 9;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    while (a[l]) l++;
    while (a[r]) r--;
    if (c[i] == 'L') {
      a[l] = 1;
      l++;
    } else if (c[i] == 'R') {
      a[r] = 1;
      r--;
    } else {
      a[c[i] - '0'] = 0;
      l = min(l, 1ll * (c[i] - '0'));
      r = max(r, 1ll * (c[i] - '0'));
    }
  }
  for (int i = 0; i <= 9; i++) cout << a[i];
  return 0;
}
