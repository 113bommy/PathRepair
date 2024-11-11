#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  int i, j;
  int s, c;
  int a[110];
  cin >> n >> k;
  for (i = 1; i <= n; i++) cin >> a[i];
  s = 0;
  c = 1;
  for (i = 1; i <= n; i++) {
    if (c == 0) break;
    if (a[i] <= k)
      s = s + 1;
    else
      for (j = n; j > i; j--) {
        if (c == 0) break;
        if (a[j] <= k)
          s = s + 1;
        else
          c = 0;
      }
  }
  cout << s << endl;
  return 0;
}
