#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cout << 1000000 + i + 1 << " ";
    }
  }
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
  return 0;
}
