#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, m, t;
  cin >> n >> k >> m >> t;
  for (int i = 0; i < t; i++) {
    int a, b;
    cin >> a >> b;
    if (a == 0 && b < k) {
      k--;
      n--;
    } else if (a == 1 && b <= k) {
      k++;
      n++;
    } else if (a == 0 && b >= k) {
      n = k;
    } else if (a == 1 && b > k) {
      n++;
    }
    cout << n << " " << k << endl;
  }
  return 0;
}
