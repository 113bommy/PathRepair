#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, f = 0, a1, a2, ind, a, b, c, d;
  cin >> n;
  for (i = 0; i < 4; i++) {
    cin >> a >> b >> c >> d;
    int diff = n - a;
    if ((diff) >= c || diff >= d) {
      f = 1;
      a1 = a;
      a2 = diff;
      ind = i + 1;
    }
    diff = n - b;
    if (diff >= c || diff >= d) {
      a1 = b;
      a2 = diff;
      f = 1;
      ind = i + 1;
    }
  }
  if (f == 1) {
    cout << ind << " " << a1 << " " << a2;
  } else {
    cout << "-1";
  }
}
