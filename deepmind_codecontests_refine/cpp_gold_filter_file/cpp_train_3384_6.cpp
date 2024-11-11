#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:32777216")
using namespace std;
int n;
int a[600000];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = 0, p = 0, st = -1;
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1] || i == n - 1) {
      if (a[i] != a[i - 1]) p++;
      ans = max(ans, p / 2);
      if (p > 1 && st != -1) {
        if (a[st] == a[i])
          for (int q = st + 1; q < i; q++) {
            a[q] = a[i];
          }
        else
          for (int q = st + 1; q < i; q++) {
            if (q - st < i - q)
              a[q] = a[st];
            else
              a[q] = a[i];
          }
      }
      st = -1;
      p = 0;
    } else {
      if (st == -1) st = i - 1;
      p++;
    }
  }
  cout << ans << endl;
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  return 0;
}
