#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  if ((n - 1) / 2 < k)
    cout << -1 << '\n';
  else {
    cout << (n * k) << '\n';
    ;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < k; j++) cout << i << ' ' << (i + j) % n + 1 << '\n';
    ;
  }
  return 0;
}
