#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    int tmp = b + 1;
    long long len = -1;
    while (tmp != 0) {
      tmp /= 10;
      len++;
    }
    long long ans = a * len;
    cout << ans << endl;
  }
  return 0;
}
