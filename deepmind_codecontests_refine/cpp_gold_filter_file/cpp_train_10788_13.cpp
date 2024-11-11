#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, x, y, cnt = 0, cnt1 = 0;
  cin >> n;
  int k = n;
  while (n--) {
    cin >> x >> y;
    if ((x > 0 && y >= 0) || (x > 0 && y < 0)) {
      cnt++;
    } else {
      cnt1++;
    }
  }
  if (cnt == k || cnt == k - 1) {
    cout << "YES" << endl;
  } else if (cnt1 == k || cnt1 == k - 1) {
    cout << "YES" << endl;
  } else
    cout << "NO" << endl;
  return 0;
}
