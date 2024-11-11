#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
struct color {
  int b, g;
};
int main() {
  int n, k;
  cin >> n >> k;
  long long cnt = 0;
  for (int i = 1; i <= k - 1; i++) {
    cnt += 2 * (k - i);
  }
  if (cnt < n) {
    cout << "no" << endl;
    return 0;
  }
  cout << "yes" << endl;
  int t = 0;
  for (int j = 1; j <= k - 1; j++) {
    for (int p = j + 1; p <= k; p++) {
      cout << j << " " << p << endl;
      t++;
      if (t == n) {
        return 0;
      }
      cout << p << " " << j << endl;
      t++;
      if (t == n) {
        return 0;
      }
    }
  }
  return 0;
}
