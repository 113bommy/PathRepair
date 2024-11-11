#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<long long> mult(32, 1);
  for (int i = 0; i < 32; i++) mult[i] = (1 << i) + 1;
  int t;
  cin >> t;
  while (t--) {
    long long d, m, final = 1;
    cin >> d >> m;
    d++;
    int x = logb(d);
    for (int i = 0; i < x; i++) {
      final *= (mult[i]) % m;
      final %= m;
    }
    final *= (d - ((1 << (x))) + 1) % m;
    cout << abs((final % m - 1) % m) << endl;
  }
  return 0;
}
