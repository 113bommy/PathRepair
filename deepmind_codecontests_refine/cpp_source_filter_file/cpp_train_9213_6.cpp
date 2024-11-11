#include <bits/stdc++.h>
using namespace std;
int gruno[] = {0, 1, 0, 1, 2};
int n, k;
int grundy(int n) {
  if (k % 2 == 0) {
    if (n == 1) {
      return 1;
    } else if (n == 2) {
      return 2;
    }
    return (n % 2 == 0 ? 1 : 0);
  } else {
    if (n <= 4) {
      return gruno[n - 1];
    }
    if (n % 2 == 1) {
      return 0;
    }
    return (grundy(n / 2) == 1 ? 2 : 1);
  }
}
int main() {
  while (cin >> n >> k) {
    int res = 0;
    int x;
    for (int i = 0; i < n; i++) {
      cin >> x;
      res ^= grundy(x);
    }
    cout << (res ? "Kevin" : "Nicky") << endl;
  }
  return 0;
}
