#include <bits/stdc++.h>
using namespace std;
long long int n, k;
int main() {
  cin >> n >> k;
  long long int cnt = (n / 2) - 1;
  if (n == 1 && !k) {
    cout << 1 << endl;
  } else if (n == 1 || k < cnt + 1) {
    cout << -1 << endl;
  } else {
    cout << (k - cnt) * 2 << " " << (k - cnt) * 3 << " ";
    for (long long int i = 3; i <= n; i++) {
      cout << (k - cnt) * 2 + i << " ";
    }
    cout << endl;
  }
  return 0;
}
