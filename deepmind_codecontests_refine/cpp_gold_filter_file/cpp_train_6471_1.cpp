#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  if (n <= 9) {
    cout << n << endl;
    exit(0);
  } else if (n <= 9 + (90 * 2)) {
    n = n - 9;
    int jk = 9 + (n / 2);
    if (n % 2 == 1) {
      jk++;
      jk = jk / 10;
      cout << jk << endl;
    } else {
      cout << jk % 10;
    }
  } else if (n <= (9 + (90 * 2) + (900 * 3))) {
    n = n - 189;
    if (n % 3 == 0) {
      int jk = 99 + (n / 3);
      cout << jk % 10;
    } else if (n % 3 == 1) {
      int jk = 99 + (n / 3);
      jk++;
      jk = jk / 100;
      cout << jk;
    } else if (n % 3 == 2) {
      int jk = 99 + (n / 3);
      jk++;
      jk = jk / 10;
      cout << jk % 10;
    }
  } else {
    n = n - 2889;
    if (n % 4 == 0) {
      int jk = 999 + (n / 4);
      cout << jk % 10;
    } else if (n % 4 == 1) {
      int jk = 999 + (n / 4);
      jk++;
      jk = jk / 1000;
      cout << jk;
    } else if (n % 4 == 2) {
      int jk = 999 + (n / 4);
      jk++;
      jk = jk / 100;
      cout << jk % 10;
    } else if (n % 4 == 3) {
      int jk = 999 + (n / 4);
      jk++;
      jk = jk / 10;
      cout << jk % 10;
    }
  }
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
