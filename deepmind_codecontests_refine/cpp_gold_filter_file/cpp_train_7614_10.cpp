#include <bits/stdc++.h>
using namespace std;
int cr[1009][1009];
int main() {
  int n, l, w, h;
  cin >> l >> n >> h;
  int ar[100009];
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  int br[100009];
  for (int i = 1; i <= l; i++) {
    cin >> br[i];
  }
  for (int i = 1; i <= l; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> cr[i][j];
      if (cr[i][j] == 1) {
        cr[i][j] = min(br[i], ar[j]);
      }
    }
  }
  for (int i = 1; i <= l; i++) {
    for (int j = 1; j <= n; j++) {
      cout << cr[i][j] << " ";
    }
    cout << endl;
  }
}
