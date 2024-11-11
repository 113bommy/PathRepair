#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, t, sum = 0;
  cin >> n >> t;
  if (t == 10 && n == 1)
    cout << "-1";
  else if (t == 10 && n > 1) {
    cout << 1;
    for (int i = 0; i < n - 1; i++) cout << '0';
  } else
    for (int i = 1; i <= n; ++i) cout << t;
  return 0;
}
