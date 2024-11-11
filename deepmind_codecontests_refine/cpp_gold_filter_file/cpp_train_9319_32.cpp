#include <bits/stdc++.h>
const int INF = 100000000;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
using namespace std;
long long f(long long *a, int l, int r) {
  long long ret = 0;
  for (int i = l; i <= r; i++) ret |= a[i];
  return ret;
}
int n;
long long a[1003], b[1003];
int main() {
  long long ans = 0;
  cin >> n;
  for (int i = 0; i < (n); i++) cin >> a[i];
  for (int i = 0; i < (n); i++) cin >> b[i];
  for (int l = 0; l < (n); l++)
    for (int r = 0; r < (n); r++)
      if (l <= r) {
        ans = max(ans, f(a, l, r) + f(b, l, r));
      }
  cout << ans << endl;
  return 0;
}
