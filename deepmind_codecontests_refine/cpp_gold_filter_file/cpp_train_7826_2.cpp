#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, t;
  cin >> n;
  for (int k = 1; k <= n; k++) {
    cin >> a >> b;
    if (a - b == 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
