#include <bits/stdc++.h>
using namespace std;
int hz[101];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for (int j = 1; j <= n; j++) {
      int y;
      cin >> y;
      hz[y]++;
    }
  }
  for (int i = 1; i <= 100; i++) {
    if (hz[i] == n) {
      cout << i << ' ';
    }
  }
  return 0;
}
