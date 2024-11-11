#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, e, x, y, say = 0, say1 = 0, v = 0;
  cin >> a;
  int d[100000];
  for (int i = 1; i <= a; i++) {
    cin >> d[i];
  }
  cin >> x >> y;
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j < i; j++) {
      say = say + d[j];
    }
    for (int k = i; k <= a; k++) {
      say1 = say1 + d[k];
    }
    if (say >= x && say <= y && say1 >= x && say <= y) {
      v = 1;
      cout << d[i] << endl;
      return 0;
    }
    say = 0;
    say1 = 0;
  }
  if (v == 0) {
    cout << 0 << endl;
  }
  return 0;
}
