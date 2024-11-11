#include <bits/stdc++.h>
using namespace std;
int i, j, k, x, a, n1, n2, mn, mx;
int t[4096];
int main() {
  cin >> x >> k;
  for (i = 0; i < k; i++) {
    cin >> a >> n2;
    if (a == 1) {
      cin >> n1;
      t[n1] = 1;
    }
    t[n2] = 2;
  }
  for (i = 1; i < x; i++) {
    j = i;
    while (t[j] == 0 && j < x) j++;
    if (j > i) {
      mx += (j - i);
      mn += (j - i + 1) / 2;
      i = j;
    }
  }
  cout << mn << " " << mx << endl;
}
