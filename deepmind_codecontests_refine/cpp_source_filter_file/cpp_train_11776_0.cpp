#include <bits/stdc++.h>
using namespace std;
long long n, k, p;
string ret;
long long t;
char f() {
  if (n == k) return 'X';
  if (k == 0) return '.';
  if (k == 1 && t < n) return '.';
  if (k == 1) return 'X';
  if (2 * k <= n) {
    if ((n - 1) % 2) {
      if (t <= (n - 2 * k + 1)) return '.';
      if ((t - n + 2 * k - 1) % 2)
        return 'X';
      else
        return '.';
    } else {
      if (t >= n - 1) return 'X';
      if (t <= (n - 2 * k + 2)) return '.';
      if ((t - n + 2 * k - 2) % 2)
        return 'X';
      else
        return '.';
    }
  }
  if (t <= 2 * k - 1 && (t % 2)) return '.';
  return 'X';
}
int main() {
  cout << setprecision(9);
  cin >> n >> k >> p;
  for (long long i = 0; i < p; i++) {
    cin >> t;
    ret += f();
  }
  cout << ret << endl;
}
