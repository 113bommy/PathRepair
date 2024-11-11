#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, t;
  cin >> n >> m;
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long s = 0;
  while (m--) {
    cin >> t;
    if (t == 1) {
      long long x, y;
      cin >> x >> y;
      arr[x - 1] = y - s;
    } else if (t == 2) {
      long long x;
      cin >> x;
      s += x;
    } else if (t == 3) {
      long long x;
      cin >> x;
      cout << arr[x - 1] + s << '\n';
    }
  }
}
