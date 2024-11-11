#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<string> A(8);
  int mnA = 1e3, mnB = 1e3;
  for (int i = 0; i < 8; i++) cin >> A[i];
  for (int i = 0; i < 8; i++)
    for (int u = 0; u < 8; u++) {
      if (A[i][u] == 'B') {
        int ans = 0;
        for (int j = i + 1; j < 8; j++) {
          ans++;
          if (A[j][u] == 'B' || A[j][u] == 'W') {
            ans = 0;
            break;
          }
        }
        if (ans) mnB = min(mnB, ans);
      } else if (A[i][u] == 'W') {
        int ans = 0;
        for (int j = i - 1; j >= 0; j--) {
          ans++;
          if (A[j][u] == 'B' || A[j][u] == 'W') {
            ans = 0;
            break;
          }
        }
        if (ans) mnA = min(mnA, ans);
      }
    }
  if (mnA < mnB)
    cout << 'A';
  else
    cout << 'B';
  return 0;
}
