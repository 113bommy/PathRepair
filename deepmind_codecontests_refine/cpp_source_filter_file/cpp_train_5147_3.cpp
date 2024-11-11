#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  if (2 * k + 1 > n)
    cout << -1 << endl;
  else {
    cout << k * n << endl;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < k; ++j)
        cout << i + 1 << " " << (i + j) % n + 1 << endl;
    }
  }
}
