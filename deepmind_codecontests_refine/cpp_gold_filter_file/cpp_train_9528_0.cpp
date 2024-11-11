#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  t = 1;
  while (t--) {
    unsigned long long n;
    cin >> n;
    cout << (n + 4) * (n + 3) / 2 * (n + 2) / 3 * (n + 1) / 4 * (n) / 5 *
                (n + 2) * (n + 1) / 2 * (n) / 3;
  }
  cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
