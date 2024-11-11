#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long n, k;
    cin >> n >> k;
    if (k % 3 != 0) {
      if (n % 3 == 0)
        cout << "Bob" << endl;
      else
        cout << "Alice" << endl;
    } else {
      n %= (k + 1);
      if (n == k || n % 3)
        cout << "Alice" << endl;
      else
        cout << "Bob" << endl;
    }
  }
  return 0;
}
