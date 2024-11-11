#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if ((n + k) % 2 != 0)
      cout << "NO\n";
    else if (n >= (k * k))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
