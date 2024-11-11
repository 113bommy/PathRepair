#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int r, c;
  cin >> r >> c;
  if (r == c && r == 1)
    cout << 0;
  else if (c == 1) {
    for (int i = 1; i <= r; i++) cout << i << "\n";
  } else {
    for (int i = 1; i <= r; i++) {
      for (int j = r + 1; j <= r + c; j++) cout << i * j << " \n"[j == r + c];
    }
  }
  return 0;
}
