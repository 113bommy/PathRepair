#include <bits/stdc++.h>
using namespace std;
int main() {
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    cout << max((n - 2), 0) << endl;
  }
  return 0;
}
