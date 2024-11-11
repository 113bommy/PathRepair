#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base ::sync_with_stdio(false);
  int test_case;
  cin >> test_case;
  while (test_case--) {
    long long a, b, n, op = 0;
    cin >> a >> b >> n;
    bool abigger = false;
    if (a < b) abigger = true;
    while (a <= n && b <= n) {
      if (abigger)
        a += b;
      else
        b += a;
      abigger = !abigger;
      op++;
    }
    cout << op << endl;
  }
  return 0;
}
