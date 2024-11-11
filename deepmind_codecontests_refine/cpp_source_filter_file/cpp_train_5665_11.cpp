#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(""
            ".in",
            "r")) {
    freopen(
        ""
        ".in",
        "r", stdin);
    freopen(
        ""
        ".out",
        "w", stdout);
  }
  int n;
  cin >> n;
  int upper = 0, lower = 0;
  bool has = false;
  while (n--) {
    int a, b;
    cin >> a >> b;
    upper += a;
    lower += b;
    if (a % 2 || b % 2 && !(a % 2 && b % 2)) {
      has = true;
    }
  }
  if (upper % 2 == 0 && lower % 2 == 0) {
    cout << 0;
  } else if (upper % 2 && lower % 2) {
    cout << (has ? 1 : -1);
  } else {
    cout << -1;
  }
}
