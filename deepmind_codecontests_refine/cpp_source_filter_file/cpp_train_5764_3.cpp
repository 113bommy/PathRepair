#include <bits/stdc++.h>
using namespace std;
int modp(int base, int exp, int m) {
  int ret = 1;
  if (exp == 0) return ret;
  ret = modp(base, exp >> 1, m);
  ret = (1LL * ret * ret) % m;
  if (exp & 1) ret = (ret * base) % m;
  return ret;
}
int main() {
  int N, M;
  cin >> N >> M;
  cout << (modp(3, N, M) - 1 + M) % M << endl;
}
