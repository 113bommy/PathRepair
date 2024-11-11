#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    int n;
    cin >> n;
    int l = 2 * n, cnt = 0;
    while (cnt <= n) {
      cnt++;
      cout << l << ' ';
      l += 2;
    }
    cout << endl;
    t--;
  }
  return 0;
}
