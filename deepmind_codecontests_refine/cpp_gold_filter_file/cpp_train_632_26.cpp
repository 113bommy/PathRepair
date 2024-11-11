#include <bits/stdc++.h>
using namespace std;
void work(long long x, long long y) {
  int p;
  cin >> p;
  for (int i = 0; i < p; i++) {
    long long q;
    cin >> q;
    if (q < x)
      cout << '.';
    else if (q == x)
      cout << 'X';
    else if (q <= x + 2 * y)
      cout << (((q - x) & 1) ? '.' : 'X');
    else
      cout << 'X';
  }
  exit(0);
}
int main() {
  long long n, k;
  cin >> n >> k;
  if (k == 0) work(1e9, 0);
  long long e = max(0LL, 2 * k - n);
  if ((e & 1) != (n & 1)) e++;
  if (e == k)
    work(n - k + 1, 0);
  else {
    long long n1 = n - e, k1 = k - e;
    work(n1 - 2 * (k1 - 1), k1 - 1);
  }
  return 0;
}
