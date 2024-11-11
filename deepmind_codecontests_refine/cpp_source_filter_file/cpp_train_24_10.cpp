#include <bits/stdc++.h>
using namespace std;
const int N = 100007;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ind;
    bool found = false;
    if (a[0] + a[1] < a[n - 1]) found = true;
    if (found) {
      cout << 1 << " " << 2 << " " << n << "\n";
    } else
      cout << "-1\n";
  }
  return 0;
}
