#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int ans = 1;
  if (k % 2 != 0) {
    int it = 1;
    while (it != k) {
      it += 2;
      ans++;
    }
  } else if (k % 2 == 0) {
    int it = 0;
    while (it != k) {
      it += 2;
      ans++;
    }
  }
  cout << ans;
}
