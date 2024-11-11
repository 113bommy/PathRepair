#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  if (n & 1 == 1) {
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
      cout << (i) - (i & 1) << " ";
    }
    for (int i = 1; i <= n; i++) {
      cout << (i) - !(i & 1) << " ";
    }
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
