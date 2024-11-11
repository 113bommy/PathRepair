#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, pos, mn = 1e9, A[200005], val;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < n; ++i) {
    if (A[i] - i <= 0) {
      cout << i + 1;
      return 0;
    } else {
      val = ceil((1.0 * A[i]) / n);
      if (mn > val) {
        mn = val;
        pos = i + 1;
      }
    }
  }
  cout << pos;
}
