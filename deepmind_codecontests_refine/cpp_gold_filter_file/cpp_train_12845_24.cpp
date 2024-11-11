#include <bits/stdc++.h>
using namespace std;
long long fp(long long n, long long p) {
  if (p == 0) return 1;
  if (p == 1) return n % (long long)(1000000007);
  long long res;
  res = fp(n, p / 2) % (long long)(1000000007);
  res = (res * res) % (long long)(1000000007);
  if (p % 2) res = (res * n) % (long long)(1000000007);
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  ;
  long long n, k;
  cin >> n >> k;
  int tot = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) tot++;
  if (tot <= k) return cout << "no solution" << '\n', 0;
  for (int i = 1; i <= n; i++) {
    cout << 1 << " " << n - i + 1 << '\n';
  }
  return 0;
}
