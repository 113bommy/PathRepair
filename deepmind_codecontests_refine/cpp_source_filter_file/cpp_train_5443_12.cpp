#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    long long maxlen = max(a, b);
    long long minlen = min(a, b);
    if ((minlen - 1) * 2 >= maxlen)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
