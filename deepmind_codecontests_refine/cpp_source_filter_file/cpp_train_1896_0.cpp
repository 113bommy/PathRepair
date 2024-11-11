#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n >= 15 && n % 14 >= 1 && n % 14 <= 6)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
