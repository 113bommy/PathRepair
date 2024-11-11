#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  long long arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long cnt = 0;
  while (m--) {
    long long x, y, z;
    cin >> x;
    if (x == 3) {
      cin >> y;
      cout << arr[y - 1] + cnt << "\n";
    } else if (x == 2) {
      cin >> y;
      cnt += y;
    } else {
      cin >> y >> z;
      arr[y - 1] = z - cnt;
    }
  }
  return 0;
}
