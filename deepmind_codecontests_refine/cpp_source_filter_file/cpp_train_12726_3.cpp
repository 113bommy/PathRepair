#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, m;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    if (n == 1)
      cout << 0 << endl;
    else if (n == 2)
      cout << n << endl;
    else
      cout << (n * 2) << endl;
  }
}
