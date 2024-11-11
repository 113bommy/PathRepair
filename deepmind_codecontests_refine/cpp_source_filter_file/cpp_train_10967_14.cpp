#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int q[2 * n + 1];
  for (int a = 0; a < 2 * n + 1; a++) {
    cin >> q[a];
  }
  for (int a = 1; a < 2 * n + 1 && k > 0; a++) {
    if (q[a] > q[a + 1] && q[a] > q[a - 1]) {
      q[a]--;
      k--;
    }
  }
  for (int a = 0; a < 2 * n + 1; a++) {
    cout << q[a] << " ";
  }
}
