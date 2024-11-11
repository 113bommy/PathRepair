#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n >> x;
  int cnt = 0;
  for (int j = 1; j * j <= x; j++) {
    if (x % j == 0) {
      if (j <= n && x / j <= n) {
        if (j * j == n)
          cnt++;
        else
          cnt += 2;
      }
    }
  }
  cout << cnt << endl;
}
