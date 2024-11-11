#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100100;
const int INF = 1000 * 1000 * 1000;
int n, a[MAXN];
int main() {
  int pos = 1;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= 301; ++i) {
    while (pos != n) {
      if (a[pos] != 0) {
        cout << "P";
        a[pos]--;
      }
      cout << "R";
      pos++;
    }
    while (pos != 1) {
      if (a[pos] != 0) {
        cout << "P";
        a[pos]--;
      }
      cout << "L";
      pos--;
    }
  }
  return 0;
}
