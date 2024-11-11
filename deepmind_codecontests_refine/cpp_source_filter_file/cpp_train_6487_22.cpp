#include <bits/stdc++.h>
using namespace std;
long long n, m, k, N, ans;
int main() {
  cin >> n >> m >> k;
  N = 1000000007;
  if (k > n && k == 1) {
    ans = 1;
    for (int i = 1; i <= n; i++) ans = (ans * m) % N;
  }
  if (k == n) {
    ans = 1;
    for (int i = 1; i <= n / 2 + n % 2; i++) ans = (ans * m) % N;
  } else if (k <= 2)
    ans = m;
  else if (k % 2 == 0)
    ans = m;
  else
    ans = m * m;
  cout << ans;
  return 0;
}
