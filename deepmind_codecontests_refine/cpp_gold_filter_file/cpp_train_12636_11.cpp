#include <bits/stdc++.h>
using namespace std;
int a[10000000], n;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) a[i] = i;
  for (int i = 2; i <= n; i++) {
    int cnt = i - 1;
    a[cnt + n] = a[cnt + (n / i) * i];
    for (int j = cnt + (n / i) * i; j >= cnt; j -= i) a[j] = a[j - i];
  }
  for (int i = 1; i <= n; i++) cout << a[n + i - 1] << " ";
}
