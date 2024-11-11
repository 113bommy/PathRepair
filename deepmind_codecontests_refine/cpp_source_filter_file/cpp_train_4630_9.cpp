#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int T[n + 1];
  int sport[n + 1];
  int math[n + 1];
  int phys[n + 1];
  int x = -1, y = -1, z = -1;
  for (int i = 1; i < n + 1; i++) {
    cin >> T[i];
    switch (T[i]) {
      case 1:
        x++;
        sport[x] = i;
        break;
      case 2:
        y++;
        math[y] = i;
        break;
      case 3:
        z++;
        phys[z] = i;
        break;
    }
  }
  int w = min(x, y);
  w = min(w, z);
  if (w == -1) {
    cout << 0;
    return 0;
  }
  cout << w;
  for (int i = 0; i < w + 1; i++) {
    cout << endl;
    cout << sport[i] << " " << math[i] << " " << phys[i];
  }
  return 0;
}
