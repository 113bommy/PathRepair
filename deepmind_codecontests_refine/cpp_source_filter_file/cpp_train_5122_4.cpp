#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, p;
  cin >> n >> p;
  for (int i = 1; i <= 1000; i++) {
    int k = n - i * p;
    int k1 = k;
    int t = 0;
    if (k <= 0) {
      cout << "-1" << '\n';
      break;
    }
    while (k != 0) {
      if (k % 2) t++;
      k /= 2;
    }
    if (k1 <= i && t <= i) {
      cout << i << '\n';
      break;
    }
    if (i == 1000) {
      cout << "-1" << '\n';
    }
  }
}
