#include <bits/stdc++.h>
using namespace std;
void input(int n, int a[]) {
  for (int i = 0; i < n; ++i) cin >> a[i];
}
long long bin_expo(long long A, long long B, long long M) {
  long long res = 1LL;
  while (B > 0) {
    if (B % 2 == 1) {
      res = (res * A) % M;
    }
    A = (A * A) % M;
    B = B / 2;
  }
  return res;
}
int main() {
  int n, m;
  cin >> n >> m;
  if (m == 1)
    cout << 1;
  else
    cout << min(m, n - m) << endl;
  return 0;
}
