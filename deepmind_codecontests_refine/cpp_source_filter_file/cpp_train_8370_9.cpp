#include <bits/stdc++.h>
using namespace std;
long long G(long long a, long long b) {
  if (b == 0) return a;
  return G(b, a % b);
}
long long q[100000 + 10], w[100000 + 10];
int main() {
  ios_base::sync_with_stdio(false);
  long long n, m, ans = 0, sum = 0;
  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> q[i] >> w[i];
  sort(w, w + m);
  reverse(w, w + m);
  if (n == 1) {
    cout << w[0];
    return 0;
  }
  for (ans = 2;; ans++) {
    long long k = ans * (ans - 1) / 2;
    if (ans % 2 == 0) k += ans / 2 - 1;
    if (k > n) break;
  }
  ans--;
  for (int i = 0; i < ans; i++) sum += w[i];
  cout << sum;
}
