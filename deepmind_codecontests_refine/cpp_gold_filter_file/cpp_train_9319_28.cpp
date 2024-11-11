#include <bits/stdc++.h>
using namespace std;
int n;
long long a[1003], b[1003];
int main() {
  cin.sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  long long ans = 0;
  long long A = 0, B = 0;
  for (int i = 1; i <= n; i++) A |= a[i], B |= b[i];
  ans = A + B;
  cout << ans << endl;
  return 0;
}
