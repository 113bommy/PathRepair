#include <bits/stdc++.h>
using namespace std;
long long n, q;
long long a[200005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 0; i < q; i++) {
    long long x;
    cin >> x;
    while (1) {
      if (x % 2 == 1) break;
      x /= 2;
      x += n;
    }
    cout << x / 2 + 1 << endl;
  }
}
