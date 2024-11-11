#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char a[n], b[n];
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 'G')
      b[i] = 1, sum++;
    else
      b[i] = 0;
  }
  int c[n], tot = 0, tmp = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] == 1) {
      tmp++;
    } else {
      if (tmp) c[tot++] = tmp, tmp = 0;
      c[tot++] = 0;
    }
  }
  if (tmp) c[tot++] = tmp, tmp = 0;
  int ans = 0, tag = 0;
  for (int i = 0; i < tot; i++) {
    if (!c[i]) {
      if (i - 1 >= 0 && i + 1 < tot && c[i - 1] && c[i + 1]) {
        if (c[i - 1] + c[i + 1] + 1 > ans && sum > c[i - 1] + c[i + 1])
          ans = c[i - 1] + c[i + 1] + 1, tag = 2;
        if (c[i - 1] + c[i + 1] == sum) ans = sum;
      }
    } else {
      if (c[i] >= ans) ans = c[i], tag = 1;
    }
  }
  if (tag == 1 && sum > ans) ans++;
  cout << ans;
  return 0;
}
