#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
long long xorall(long long n) {
  long long res = 0;
  for (int i = 0; i < 62; ++i) {
    if (i) {
      if (n & (1LL << i) && n % 2 == 0) res |= 1LL << i;
    } else {
      if (((n + 1) / 2) % 2) res |= 1;
    }
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  long long gr = 0;
  for (int i = 0; i < n; ++i) {
    long long m, x;
    cin >> m >> x;
    gr ^= xorall(x + m - 1) ^ xorall(m - 1);
  }
  if (gr)
    cout << "tolik";
  else
    cout << "bolik";
  return 0;
}
