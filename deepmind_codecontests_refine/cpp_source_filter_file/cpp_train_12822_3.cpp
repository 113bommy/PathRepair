#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, k, i;
  cin >> n >> m >> k;
  long long int a[m];
  for (i = 0; i < m; i++) {
    cin >> a[i];
  }
  long long int cnt = 0;
  long long int ans = 0;
  for (i = 0; i < m;) {
    long long int c = (a[i] - cnt - 1) / k;
    long long int j = i;
    while ((((a[i] - cnt - 1) / k) <= c) && i < m) {
      i++;
    }
    cnt = i - j;
    ans++;
  }
  cout << ans << endl;
}
