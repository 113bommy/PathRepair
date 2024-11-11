#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int histA[6] = {};
  int histB[6] = {};
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    histA[x]++;
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    histB[x]++;
  }
  for (int i = 1; i <= 5; i++) {
    if ((histA[i] + histB[i]) % 2 == 1) {
      cout << -1 << endl;
      return 0;
    }
  }
  int hist[6] = {};
  for (int i = 1; i <= 5; i++) {
    hist[i] = abs(histA[i] - histB[i]) / 2;
  }
  int ans = 0;
  for (int i = 1; i <= 5; i++) {
    if (hist[i]) {
      if (histA[i] > histB[i]) {
        for (int j = 1; j <= 5; j++) {
          if (j == i) continue;
          if (hist[j] && histB[i] > histA[i]) {
            int m = min(hist[i], hist[j]);
            hist[i] -= m;
            hist[j] -= m;
            ans += m;
          }
        }
      } else {
        for (int j = 1; j <= 5; j++) {
          if (j == i) continue;
          if (hist[j] && histA[i] > histB[i]) {
            int m = min(hist[i], hist[j]);
            hist[i] -= m;
            hist[j] -= m;
            ans += m;
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
