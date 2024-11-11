#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  int h[n], g[n], i, j;
  for (i = 0; i < n; i++) {
    cin >> h[i] >> g[i];
  }
  int tot = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (h[i] == g[i]) tot++;
    }
  }
  cout << tot;
  return 0;
}
