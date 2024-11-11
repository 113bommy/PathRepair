#include <bits/stdc++.h>
using namespace std;
const long long INFLL = 2 * (long long)1e18 + 100;
const int INFINT = 2 * (int)1e9 + 100;
const double PI = atan(1) * 4;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int NMAX = 300 + 5;
int grundy[] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6,  2, 1, 8, 7,  5,
                9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};
long long n;
map<long long, bool> trecut;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  int rem = n, x = 0;
  for (long long i = 2; i <= sqrt(n); i++) {
    if (!trecut[i]) {
      int val_cur = 0;
      for (long long j = i; j <= n; j *= i) {
        trecut[j] = 1;
        rem--;
        val_cur++;
      }
      x ^= grundy[val_cur];
    }
  }
  x ^= rem % 2;
  if (x)
    cout << "Vasya";
  else
    cout << "Petya";
  return 0;
}
