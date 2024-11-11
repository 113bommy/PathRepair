#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  int a, i, c = 1, k, max;
  cin >> a;
  int b[a], x[a];
  for (i = 0; i < a; i++) {
    cin >> b[i];
  }
  max = b[0];
  for (i = 1; i < a; i++) {
    if (b[i] >= b[i - 1]) {
      c++;
    } else {
      if (max <= c) max = c;
      c = 1;
    }
    if (max <= c) max = c;
  }
  cout << max << endl;
}
