#include <bits/stdc++.h>
using namespace std;
bool toppled[101];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      int x;
      cin >> x;
      switch (x) {
        case -1:
        case 0:
          break;
        case 1:
          toppled[i] = true;
          break;
        case 2:
          toppled[j] = true;
          break;
        case 3:
          toppled[i] = true;
          toppled[j] = true;
          break;
        default:
          break;
      }
    }
  int ct = 0;
  for (int i = 1; i <= n; ++i)
    if (!toppled[i]) ++ct;
  cout << ct << "\n";
  if (ct > 0) {
    int i = 1;
    while (toppled[i]) ++i;
    cout << i++;
    while (i <= n)
      if (!toppled[i++]) cout << " " << (i - 1);
  }
  cout << "\n";
  return 0;
}
