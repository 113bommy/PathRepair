#include <bits/stdc++.h>
long long int power(long long int x, long long int b) {
  long long int p = 1;
  while (b > 0) {
    if (b & 1) {
      p = p * x;
      p %= 998244353;
    }
    b >>= 1;
    x *= x;
    x %= 998244353;
  }
  return p % 998244353;
}
using namespace std;
int main() {
  long long int n, k, a, b;
  cin >> n >> k;
  map<long long int, long long int> m;
  n = k + 1;
  for (long long int i = 1; i <= n; i++) {
    cout << "? ";
    for (long long int j = 1; j <= n; j++)
      if (i != j) cout << j << " ";
    cout << endl;
    cout.flush();
    cin >> a >> b;
    m[b]++;
  }
  auto it = m.begin();
  it++;
  cout << "! " << (*it).second << endl;
  return 0;
}
