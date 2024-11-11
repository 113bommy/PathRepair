#include <bits/stdc++.h>
using namespace std;
long long a[30];
long long ans;
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[x + 10]++;
  }
  for (int i = 1; i <= 10; i++) ans += (a[i + 10] * a[10 - i]);
  ans += a[10] * (a[10] - 1) / 2;
  cout << ans << endl;
  return 0;
}
