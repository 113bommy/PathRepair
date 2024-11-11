#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, s, A[102], now = 0;
  cin >> n >> s;
  for (i = 0; i < n; i++) {
    int h, m;
    cin >> h >> m;
    A[i] = h * 60 + m;
  }
  for (i = 0; i < n; i++) {
    if (now + 1 + s <= A[i]) {
      cout << now / 60 << " " << now % 60;
      break;
    } else {
      now = A[i] + 1 + s;
    }
  }
  if (i == n) cout << now / 60 << " " << now % 60;
  return 0;
}
