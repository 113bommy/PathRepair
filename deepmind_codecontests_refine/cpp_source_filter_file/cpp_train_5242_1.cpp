#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, res;
  cin >> n;
  if (n == 3)
    cout << 5 << endl;
  else if (n == 1)
    cout << 1 << endl;
  else {
    vector<long long> v(25);
    for (long long i = 3; i < 25; i += 2) {
      v[i] = (i * i + 1) / 2;
      if (n < v[i]) {
        res = i;
        break;
      }
    }
    cout << res << endl;
  }
  return 0;
}
