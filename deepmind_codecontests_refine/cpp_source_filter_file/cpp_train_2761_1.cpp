#include <bits/stdc++.h>
using namespace std;
long long a_fa[2500000];
long long b_fa[2500000];
long long a_tomb[250000];
long long b_tomb[250000];
void mod(long long num, long long k, long long v, long long mit, long long mire,
         long long* t, long long* m, long long mini) {
  if (k == v) {
    t[mit] = min(t[mit] + mire, mini);
    m[num] = t[mit];
    return;
  }
  if (mit <= ((k + v) / 2)) {
    mod(2 * num, k, (k + v) / 2, mit, mire, t, m, mini);
  } else {
    mod(2 * num + 1, (k + v) / 2 + 1, v, mit, mire, t, m, mini);
  }
  m[num] = m[2 * num] + m[2 * num + 1];
}
long long kerd(long long num, long long k, long long v, long long i,
               long long j, long long* m) {
  if (v < i || k > j) return -1;
  if (k >= i && v <= j) return m[num];
  long long bal = kerd(num * 2, k, (k + v) / 2, i, j, m);
  long long jobb = kerd(num * 2 + 1, (k + v) / 2 + 1, v, i, j, m);
  if (bal == -1) return jobb;
  if (jobb == -1) return bal;
  return max(bal, jobb);
}
long long n, a, k, q, b, x, y;
int main() {
  cin >> n >> k >> a >> b >> q;
  n++;
  for (long long i = 0; i < q; i++) {
    long long c;
    cin >> c;
    if (c == 1) {
      cin >> x >> y;
      mod(1, 0, n - 1, x, y, a_tomb, a_fa, a);
      mod(1, 0, n - 1, x, y, b_tomb, b_fa, b);
    }
    if (c == 2) {
      cin >> x;
      cout << kerd(1, 0, n - 1, 0, x - 1, b_fa) +
                  kerd(1, 0, n - 1, x + k, n - 1, a_fa)
           << endl;
    }
  }
  return 0;
}
