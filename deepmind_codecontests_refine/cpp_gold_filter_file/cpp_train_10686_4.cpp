#include <bits/stdc++.h>
using namespace std;
inline void file() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
long long n;
long long GetAns2(long long x) {
  long long k = 2 * (n - x) + 1;
  long long pos = x * 2 - 1;
  while (k < pos) {
    pos -= k;
    k *= 2;
  }
  return pos;
}
long long pow2(long long y) {
  if (y == 1) return 2;
  if (y == 0) return 1;
  if (y % 2) {
    long long cur = pow2(y / 2);
    return 2 * cur * cur;
  } else {
    long long cur = pow2(y / 2);
    return cur * cur;
  }
}
long long GetAns(long long pos) {
  for (long long k = 61; k >= 0; k--) {
    long long cur = pow2(k);
    if ((2 * n - pos) % cur == 0 && (2 * n - pos) / cur > 0) {
      long long step = (2 * n - pos) / cur;
      if ((2 * n + 1 - step) % 2) continue;
      long long x = (2 * n + 1 - step) / 2;
      return x;
    }
  }
  return (pos + 1) / 2;
}
int main() {
  file();
  int q;
  cin >> n >> q;
  while (q--) {
    long long x;
    cin >> x;
    cout << GetAns(x) << '\n';
  }
  return 0;
}
