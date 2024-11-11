#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  ll t;
  cin >> t;
  while (t--) {
    int c, d;
    cin >> c >> d;
    if (abs(d - c) % 2 == 1) {
      cout << "-1\n";
    } else {
      if (d == c) {
        if (d == 0) {
          cout << "0\n";
        } else {
          cout << "1\n";
        }
      } else {
        cout << "2\n";
      }
    }
  }
  return 0;
}
