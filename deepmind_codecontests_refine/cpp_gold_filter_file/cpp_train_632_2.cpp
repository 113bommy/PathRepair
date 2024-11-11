#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
long long n, k, p;
char query(long long q) {
  if (k > 0 && n == q)
    return 'X';
  else if (q % 2 == 1) {
    long long r = n / 2 - q / 2;
    long long nk = (n % 2 == 1) ? (k - 1 - n / 2) : (k - n / 2);
    if (r <= nk)
      return 'X';
    else
      return '.';
  } else {
    long long r = n / 2 - q / 2 + 1;
    long long nk = (n % 2 == 1) ? (k - 1) : k;
    if (r <= nk)
      return 'X';
    else
      return '.';
  }
}
int main() {
  cin >> n >> k >> p;
  for (int i = 0; i < p; ++i) {
    long long q;
    cin >> q;
    cout << query(q);
  }
  cout << endl;
  return 0;
}
