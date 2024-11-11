#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  unsigned long long v[30];
  v[0] = 1;
  for (int i = 1; i < (n); i++) v[i] = v[i - 1] << 2;
  unsigned long long ans = (v[n - 2] * 3) << 1;
  ans += (n - 3) * (v[n - 3] * 9);
  cout << ans << endl;
}
