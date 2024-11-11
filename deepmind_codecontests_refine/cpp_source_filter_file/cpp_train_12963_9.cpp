#include <bits/stdc++.h>
using namespace std;
int mal[366], fem[366];
int main() {
  int n;
  cin >> n;
  char a[2];
  int b, c;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b >> c;
    if (a[0] == 'M')
      for (int j = b; j <= c; j++) {
        mal[j]++;
      }
    else {
      for (int j = b; j <= c; j++) {
        fem[j]++;
      }
    }
  }
  int mina = 0;
  for (int i = 0; i < 366; ++i) {
    mina = max(mina, min(mal[i], fem[i]));
  }
  cout << 2 * mina << endl;
  return 0;
}
