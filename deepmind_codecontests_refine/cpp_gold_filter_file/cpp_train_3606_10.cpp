#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, i, num = -10000000, n, j, tm = 0;
  float tmp;
  cin >> n;
  int a;
  for (i = 0; i < n; i++) {
    cin >> a;
    if (a >= 0) {
      tmp = sqrt(a);
      if (tmp != ceil(tmp)) {
        if (num < a) {
          num = a;
        }
      }
    } else {
      if (a > num) {
        num = a;
      }
    }
  }
  cout << num;
  return 0;
}
