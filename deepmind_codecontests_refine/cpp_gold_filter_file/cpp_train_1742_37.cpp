#include <bits/stdc++.h>
using namespace std;
map<long long, bool> marked;
long long n, v, vv, ss = 100, ans, border = 5000;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (long long a = 0; a <= ss; a++) {
    for (long long b = 0; b <= ss; b++) {
      for (long long c = 0; c <= ss; c++) {
        if (a + b + c <= n) {
          v = 50 * n;
          vv = 49 * a + 45 * b + 40 * c;
          marked[v - vv] = 1;
        }
      }
    }
  }
  for (long long a = n; n - a <= ss && a >= 0; a--) {
    for (long long b = 0; b <= ss; b++) {
      for (long long c = 0; c <= ss; c++) {
        if (a + b + c <= n) {
          v = 50 * n;
          vv = 49 * a + 45 * b + 40 * c;
          marked[v - vv] = 1;
        }
      }
    }
  }
  for (long long a = n; n - a <= ss && a >= 0; a--) {
    for (long long b = 0; b <= ss; b++) {
      for (long long c = 0; c <= ss; c++) {
        if (a + b + c <= n) {
          v = 50 * n;
          vv = 45 * a + 40 * b + 49 * c;
          marked[v - vv] = 1;
        }
      }
    }
  }
  for (long long a = n; n - a <= ss && a >= 0; a--) {
    for (long long b = 0; b <= ss; b++) {
      for (long long c = 0; c <= ss; c++) {
        if (a + b + c <= n) {
          v = 50 * n;
          vv = 40 * a + 49 * b + 45 * c;
          marked[v - vv] = 1;
        }
      }
    }
  }
  long long place = n - 1, cont = 0;
  for (long long a = n; a <= 50 * n; a++) {
    place++;
    if (marked[a]) {
      cont++;
      ans++;
    } else
      cont = 0;
    if (cont == 100) break;
  }
  long long place2 = 50 * n + 1;
  cont = 0;
  for (long long a = 50 * n; a >= 0; a--) {
    if (a == place) break;
    place2--;
    if (marked[a]) {
      cont++;
      ans++;
    } else
      cont = 0;
    if (cont == 100) break;
  }
  if (place2 > place) ans += place2 - place - 1;
  cout << ans << endl;
  return 0;
}
