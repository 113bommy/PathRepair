#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const* argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int& i : v) {
      cin >> i;
    }
    int res = 0, f = 0;
    for (int i = 1; i < n; ++i) {
      while (v[i]) {
        k -= i;
        if (k < 1) {
          break;
        }
        res += 1;
        v[i] -= 1;
      }
      if (k < 1) {
        break;
      }
    }
    cout << v[0] + res << "\n";
  }
  return 0;
}
