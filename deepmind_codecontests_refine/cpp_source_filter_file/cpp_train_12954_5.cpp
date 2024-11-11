#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a, i;
  cin >> n >> k;
  if (k < n / 2 || (n < 2 && k == 1)) {
    cout << -1 << endl;
    return 0;
  } else {
    long long a = (k + 1) - n / 2;
    cout << a << " ";
    a *= 2;
    n--;
    while (n--) cout << (a++) << " ";
  }
  return 0;
}
