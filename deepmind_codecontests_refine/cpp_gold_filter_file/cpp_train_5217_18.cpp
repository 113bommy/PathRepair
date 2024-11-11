#include <bits/stdc++.h>
using namespace std;
void kehsihba() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int32_t main() {
  kehsihba();
  long long n;
  cin >> n;
  if (n <= 10) {
    cout << 0;
  } else {
    long long res = n - 10;
    if (res <= 9) {
      cout << 4;
    } else {
      if (res == 10) {
        cout << 15;
      } else if (res == 11) {
        cout << 4;
      } else {
        cout << 0;
      }
    }
  }
  return 0;
}
