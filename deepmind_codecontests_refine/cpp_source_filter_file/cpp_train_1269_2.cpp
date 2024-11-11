#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  long long f[100005];
  f[0] = 0;
  f[1] = 1;
  for (int i = 2; i <= 100000; i++) f[i] = (f[i - 1] + f[i - 2]) % 1000000007;
  int n, m;
  cin >> n >> m;
  cout << (f[n + 1] + f[m + 1] - 1) * 2 % 1000000007 << "\n";
  return 0;
}
