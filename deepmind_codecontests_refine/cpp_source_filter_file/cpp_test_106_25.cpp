#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.1415926535897932384626433832795;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = n; i >= 1; i--) {
      cout << i << " ";
    }
    cout << '\n';
  }
  return 0;
}
