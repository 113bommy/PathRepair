#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  long long int n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    if (n == 1)
      cout << 0;
    else if (n == 2)
      cout << m;
    else {
      cout << 2 * n;
    }
    cout << endl;
  }
  return 0;
}
