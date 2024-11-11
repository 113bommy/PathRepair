#include <bits/stdc++.h>
using namespace std;
const int INF = 1000 * 1000 * 1000;
const long long INF64 = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL;
long long n, k;
int p;
void Load() { cin >> n >> k >> p; }
void Solve() {
  long long z, y, x, t;
  y = n - k;
  for (int i = 0; i < p; i++) {
    cin >> x;
    if (k == 0)
      cout << ".";
    else if (k == 1) {
      if (x == n)
        cout << "X";
      else
        cout << ".";
    } else {
      if (n - 2 * k <= 0) {
        if (x > 2 * y - 1)
          cout << "X";
        else if (x & 1)
          cout << ".";
        else
          cout << "X";
      } else {
        if (x == n) {
          cout << "X";
          continue;
        }
        if (!(n & 1)) {
          if (x <= n - 2 * k + 1)
            cout << ".";
          else {
            if (x & 1)
              cout << ".";
            else
              cout << "X";
          }
        } else {
          if (x <= n - 2 * k + 2)
            cout << ".";
          else {
            if (x & 1)
              cout << ".";
            else
              cout << "X";
          }
        }
      }
    }
  }
}
int main() {
  Load();
  Solve();
  return 0;
}
