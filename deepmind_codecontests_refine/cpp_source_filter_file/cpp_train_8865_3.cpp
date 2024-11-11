#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long n, k;
    cin >> n >> k;
    if (k % 3 == 0) {
      if (n % 3 == 0)
        cout << "Bob" << endl;
      else
        cout << "Alice" << endl;
    } else {
      n %= (k + 1);
      if (n == k || n % 3 == 0)
        cout << "Alice" << endl;
      else
        cout << "bob" << endl;
    }
  }
  return 0;
}
