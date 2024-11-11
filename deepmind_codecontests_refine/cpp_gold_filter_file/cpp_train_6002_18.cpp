#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long int n, m;
  cin >> n >> m;
  long long int sum = (n * (n + 1)) / 2;
  if (sum < m) m %= sum;
  if (sum == m)
    cout << 0;
  else {
    long long int temp = (sqrt(1 + 8 * m) - 1) / 2;
    sum = (temp * (temp + 1)) / 2;
    cout << m - sum;
  }
  return 0;
}
