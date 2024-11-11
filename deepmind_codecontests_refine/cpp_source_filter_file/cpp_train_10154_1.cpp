#include <bits/stdc++.h>
using namespace std;
const int MAXL = 62;
const int MAXN = 5e5 + 10;
struct LinearBasis {
  int cnt;
  long long b[MAXL + 1];
  LinearBasis() : cnt(0) { memset(b, 0, sizeof(b)); }
  bool insert(long long x) {
    for (int i = MAXL; i >= 0; i--) {
      if (!(x >> i & 1)) continue;
      if (x >> i & b[i])
        x ^= b[i];
      else {
        for (int j = i - 1; j >= 0; j--) {
          if (1LL << j & x) x ^= b[j];
        }
        for (int j = i + 1; j <= MAXL; j++) {
          if (1LL << i & b[j]) b[j] ^= x;
        }
        b[i] = x;
        return cnt++, true;
      }
    }
    return false;
  }
};
long long s = 0, a[MAXN], b[MAXN];
LinearBasis lb = LinearBasis();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  for (int i = 0; i < n; i++) {
    s ^= a[i];
    lb.insert(a[i] ^ b[i]);
  }
  if (lb.insert(s))
    cout << "1/1";
  else
    cout << (1LL << lb.cnt) - 1 << '/' << (1LL << lb.cnt);
  return 0;
}
