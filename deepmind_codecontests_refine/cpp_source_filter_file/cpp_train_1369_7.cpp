#include <bits/stdc++.h>
using namespace std;
long long ar[10005], ck[1005];
int main() {
  long long n, i, j, k;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> ar[i];
  long long b = 0, cnt = 0;
  for (i = 1; i <= n; i++) {
    if (ck[i] == 0) {
      b = ar[i];
      long long mx = ar[i];
      for (j = i; j <= mx; j++) {
        ck[j] = -1;
        b = ar[j];
        mx = max(mx, b);
      }
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}
