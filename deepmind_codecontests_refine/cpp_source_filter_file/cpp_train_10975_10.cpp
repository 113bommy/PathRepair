#include <bits/stdc++.h>
const int N = 1000009;
using namespace std;
string s;
char a[N];
int l, r, x, n, i, used[2 * N];
bool ok(int mid) {
  int x = 0;
  for (int i = -N; i <= N; i++) used[N + i] = 0;
  for (int i = 1; i <= n; i++) {
    used[N + x]++;
    if (a[i] == 'L')
      x--;
    else
      x++;
    if (x == mid) x++;
  }
  return (used[N + x] == 0);
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> s;
  n = s.length();
  for (i = 0; i < n; i++) a[i + 1] = s[i];
  if (a[n] == 'L')
    for (i = 1; i <= n; i++)
      if (a[i] == 'L')
        a[i] = 'R';
      else
        a[i] = 'L';
  x = 0;
  for (i = 1; i <= n; i++) {
    used[N + x]++;
    if (a[i] == 'R')
      x = x + 1;
    else
      x = x - 1;
  }
  if (used[N + x] == 0) {
    cout << 1;
    return 0;
  }
  l = -10000000;
  r = -1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (ok(mid))
      r = mid;
    else
      l = mid;
  }
  cout << abs(r);
}
