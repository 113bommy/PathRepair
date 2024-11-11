#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:50000000")
using namespace std;
long long n, m, k;
long long A[10000];
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) cin >> A[i];
  if (n == 2) {
    cout << 0 << endl;
    return 0;
  }
  long long res = 0, c, o;
  c = A[0];
  for (int i = 0; i < n; ++i)
    if (i % 2 == 0 && (n - i - 1) % 2 == 0) c = min(c, A[i]);
  o = ((n - 1) / 2) + 1;
  long long can = m / o;
  res = min(c, can * k);
  cout << res << endl;
  return 0;
}
