#include <bits/stdc++.h>
using namespace std;
using namespace std;
long long f[10000];
int n;
int main() {
  cin >> n;
  f[0] = 2;
  f[1] = 3;
  if (n == 2) {
    cout << 1;
    return 0;
  }
  if (n == 3) {
    cout << 2;
    return 0;
  }
  for (int i = 2;; i++) {
    f[i] = f[i - 1] + f[i - 2];
    if (f[i] >= n) {
      cout << i;
      return 0;
    }
  }
  return 0;
}
