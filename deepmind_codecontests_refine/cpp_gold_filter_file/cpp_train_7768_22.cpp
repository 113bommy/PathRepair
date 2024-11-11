#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, a, s = 0, n;
  cin >> n;
  cin >> x;
  for (int i = 0; i < n; i++) {
    cin >> a;
    s += a;
  }
  if ((n == 1) && (x == s))
    cout << "YES";
  else if ((x == (s + (n - 1))) && (n > 1))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
