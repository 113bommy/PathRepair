#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, total;
  string res = "NO";
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    total += a;
  }
  if (n > 1) {
    if (n - total == 1) res = "YES";
  } else {
    if (n == total) res = "YES";
  }
  cout << res << endl;
  return 0;
}
