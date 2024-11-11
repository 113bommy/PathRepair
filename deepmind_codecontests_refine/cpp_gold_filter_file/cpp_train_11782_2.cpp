#include <bits/stdc++.h>
using namespace std;
int main() {
  long long q, k, n, b, a, moves;
  cin >> q;
  while (q--) {
    cin >> k >> n >> a >> b;
    k -= n * a;
    if (k > 0)
      cout << n << '\n';
    else {
      k = -k;
      moves = (k + a - b) / (a - b);
      if (n < moves)
        cout << -1 << '\n';
      else
        cout << n - moves << '\n';
    }
  }
}
