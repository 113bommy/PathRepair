#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 77;
int32_t main() {
  long long n, k;
  cin >> n >> k;
  if (k > n)
    cout << -1 << '\n';
  else {
    string s = string(n, 'a');
    if (k == 1) {
      if (n == 1)
        cout << 1 << '\n';
      else
        cout << -1 << '\n';
      return 0;
    }
    for (long long(i) = (0); (i) < (n); (i)++)
      if (i % 2 == 1) s[i] = 'b';
    long long v = n - (k - 2);
    char a = 'c';
    for (long long(i) = (v); (i) < (n); (i)++) s[i] = a++;
    cout << s << '\n';
  }
  return 0;
}
