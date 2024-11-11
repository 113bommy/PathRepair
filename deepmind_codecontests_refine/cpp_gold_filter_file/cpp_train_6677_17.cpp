#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    long long int a, b, n;
    cin >> n >> a >> b;
    if (2 * a <= b) {
      cout << n * a << endl;
    } else {
      if (n % 2)
        cout << ((n - 1) * b) / 2 + a << endl;
      else
        cout << (n * b) / 2 << endl;
    }
  }
  return 0;
}
