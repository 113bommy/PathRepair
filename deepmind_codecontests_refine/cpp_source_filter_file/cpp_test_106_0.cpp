#include <bits/stdc++.h>
using namespace std;
int t, n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 2; i <= n; i++) cout << i << " ";
    cout << "\n";
  }
}
