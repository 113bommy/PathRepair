#include <bits/stdc++.h>
using namespace std;
const double pi = 3.1415926535897932384626433832795;
long long getXorStupid(long long a) {
  long long res = 0;
  for (long long i = 0; i <= a; i++) res ^= i;
  return res;
}
long long getXor(long long a) {
  if (a % 4 == 0) return a;
  if (a % 4 == 1) return 1;
  if (a % 4 == 2) return a + 1;
  return 0;
}
long long getXor(long long a, long long b) { return getXor(b) ^ getXor(a - 1); }
int main() {
  int n;
  cin >> n;
  long long res = 0;
  for (int i = 0; i < (n); i++) {
    long long x, m;
    cin >> x >> m;
    long long xx = getXor(x, x + m - 1);
    res ^= xx;
  }
  if (res)
    cout << "tolik";
  else
    cout << "bolik";
}
