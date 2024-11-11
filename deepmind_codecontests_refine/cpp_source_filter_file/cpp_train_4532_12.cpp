#include <bits/stdc++.h>
using namespace std;
const int N = 1e1 + 7;
int n, x, y, a1, a2, b1, b2, ANS, ans, k, r, c;
bool table[N][N];
int main() {
  cin >> r >> c >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    table[y][x] = 1;
  }
  for (int b1 = 1; b1 <= r; b1++) {
    for (int b2 = b1; b2 <= r; b2++) {
      for (int a1 = 1; a1 <= c; a1++) {
        for (int a2 = a1; a2 <= c; a2++) {
          for (int i = b1; i <= b2; i++) {
            for (int j = a1; j <= a2; j++) {
              if (table[i][j]) {
                ans++;
              }
            }
          }
          if (ans >= k) {
            ANS++;
          }
          ans = 0;
        }
      }
    }
  }
  cout << ANS;
  return 0;
}
