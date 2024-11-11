#include <bits/stdc++.h>
using namespace std;
long long md;
void MD(long long &v) { v %= md; }
inline long long pwr(int x, int n) {
  long long rslt = 1, z = x;
  while (0 < n) {
    if (n % 2 == 1) MD(rslt *= z);
    n >>= 1;
    MD(z *= z);
  }
  return rslt;
}
int main() {
  int n;
  cin >> n >> md;
  int ans = pwr(3, n);
  cout << (ans == 0 ? md - 1 : ans - 1) << endl;
  return 0;
}
