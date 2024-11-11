#include <bits/stdc++.h>
bool pr[3001];
int prm[3001];
using namespace std;
void primes() {
  int i, j;
  for (i = 0; i < 3001; i++) pr[i] = true;
  pr[0] = false;
  pr[1] = false;
  for (i = 2; i <= sqrt(3000); i++) {
    if (pr[i]) {
      for (j = i; i * j <= 3001; j += 1) {
        pr[i * j] = false;
      }
    }
  }
}
int main() {
  primes();
  int n, i, k = 0, j, ans = 0;
  cin >> n;
  for (i = 0; i < 3001; i++) {
    if (pr[i]) prm[k++] = i;
  }
  for (j = 6; j <= n; j++) {
    int ct = 0;
    for (i = 0; prm[i] <= j; i++) {
      if (j >= k) break;
      if (j % prm[i] == 0) ct++;
    }
    if (ct == 2) ans++;
  }
  cout << ans;
  return 0;
}
