#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    cout << ((n * m + 1) / 2) << endl;
  }
}
