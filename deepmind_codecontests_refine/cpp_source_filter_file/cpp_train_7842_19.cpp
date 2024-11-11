#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long k, b, n, t;
  cin >> k >> b >> n >> t;
  long long a = 1;
  while (t > a) a = k * a + b, n--;
  cout << max(0LL, n + 1);
}
