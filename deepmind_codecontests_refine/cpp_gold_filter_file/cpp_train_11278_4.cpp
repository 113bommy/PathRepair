#include <bits/stdc++.h>
using namespace std;
int a[100000], b[100000];
int main() {
  int f, t, c, d, i;
  cin >> f >> t >> c >> d;
  a[0] = d;
  for (i = 1;; i++) {
    a[i] = (((f * a[i - 1]) + t) % c);
    if (b[a[i]] == 0) {
      b[a[i]] = i;
    } else {
      break;
    }
  }
  cout << i - b[a[i]] << endl;
}
