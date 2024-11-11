#include <bits/stdc++.h>
using namespace std;
long long n, A[200026], b[200026];
long long query(long long x) {
  if (b[x] != 1e18) return b[x];
  long long a1 = 0, b1 = 0;
  cout << "? " << x << endl;
  cin >> a1;
  cout << "? " << x + n / 2 << endl;
  cin >> b1;
  return b[x] = b[x + n / 2] = a1 - b1;
}
long long tryans(long long x) {
  if (query(x) == 0) {
    cout << "! " << x << '\n';
    exit(0);
  }
  return query(x);
}
bool negative(long long x) { return x < 0; }
int main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) b[i] = 1e18;
  if (n / 2 % 2 == 1) {
    cout << -1;
    return 0;
  }
  long long st = 1, en = n / 2, mid;
  tryans(st);
  while (en - st > 1) {
    mid = ((st + en) / 2);
    if (negative(tryans(mid)) != negative(tryans(st)))
      en = mid;
    else
      st = mid;
  }
  tryans(st);
  tryans(en);
}
