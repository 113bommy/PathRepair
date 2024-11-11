#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  long long n, m;
  while (t--) {
    cin >> n >> m;
    if (n == 1)
      cout << 0 << endl;
    else if (n < 3)
      cout << m << endl;
    else
      cout << m * 2 << endl;
  }
}
