#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long test_case;
  cin >> test_case;
  while (test_case--) {
    long long a;
    cin >> a;
    cout << (a % 4 == 0 ? "YES\n" : "NO\n");
  }
}
