#include <bits/stdc++.h>
using namespace std;
int l, w, h, fr[110], le[110], top[110][110];
int main() {
  cin >> l >> w >> h;
  for (int i = 1; i <= w; i++) {
    cin >> fr[i];
  }
  for (int i = 1; i <= l; i++) {
    cin >> le[i];
  }
  for (int i = 1; i <= l; i++) {
    for (int j = 1; j <= w; j++) {
      int a;
      cin >> a;
      if (a >= 0) {
        top[i][j] = fr[j];
      }
    }
  }
  for (int i = 1; i <= l; i++) {
    for (int j = 1; j <= w; j++) {
      if (top[i][j]) {
        top[i][j] = min(fr[j], le[i]);
      }
    }
  }
  for (int i = 1; i <= l; i++) {
    for (int j = 1; j <= w; j++) {
      cout << top[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
