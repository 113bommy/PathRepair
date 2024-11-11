#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a = 0, k = 10000000;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x % n <= i)
      x = x / n;
    else
      x = x / n + 1;
    if (x < k) {
      a = i;
      k = x;
    }
  }
  cout << (a + 1);
}
