#include <bits/stdc++.h>
using namespace std;
long long const mod = 1e9 + 7;
long long const N = 1e9 + 10;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, a[111] = {}, sol = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    if ((a[i] == 1 || a[i] == 2) && a[i + 1] == a[i])
      a[i + 1] = 0;
    else if (a[i] == 0)
      sol++;
    else if (a[i] == 3) {
      int c = 0;
      if (i > 0 && a[i - 1] == 1) {
        a[i] = 2;
        while (i < n - 1 && a[i + 1] == 3) {
          if (c % 2 == 0)
            a[i + 1] = 1;
          else
            a[i + 1] = 2;
          i++, c++;
        }
        if (i == n - 1 && a[i - 1] == a[i])
          sol++;
        else if (i < n - 1 && a[i] == a[i + 1])
          a[i + 1] = 0;
      } else if (i > 0 && a[i - 1] == 2) {
        a[i] = 1, c = 0;
        while (i < n - 1 && a[i + 1] == 3) {
          if (c % 2 == 0)
            a[i + 1] = 2;
          else
            a[i + 1] = 1;
          i++, c++;
        }
        if (i == n - 1 && a[i - 1] == a[i])
          sol++;
        else if (i < n - 1 && a[i] == a[i + 1])
          a[i + 1] = 0;
      } else if (i == 0) {
        while (i < n && a[i + 1] == 3) i++;
      }
    }
  }
  cout << sol;
  return 0;
}
