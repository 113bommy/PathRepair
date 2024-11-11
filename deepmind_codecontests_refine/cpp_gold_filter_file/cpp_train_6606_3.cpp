#include <bits/stdc++.h>
using namespace std;
int solve(int xx, int yy) {
  if (xx) {
    return solve(xx - 1, yy - 1) + solve(xx - 1, yy + 1);
  } else if (yy == 0) {
    return 1;
  } else {
    return 0;
  }
}
int main() {
  string x, y;
  cin >> x >> y;
  int a = 0, b = 0, c = 0;
  for (int i = 0; i < x.length(); i++) {
    if (x[i] == '+') {
      a++;
    }
    if (x[i] == '-') {
      a--;
      cout << "\n";
    }
    if (y[i] == '+') {
      b++;
    }
    if (y[i] == '-') {
      b--;
    }
    if (y[i] == '?') {
      c++;
    }
  }
  cout << fixed << setprecision(9) << (double)solve(c, a - b) / pow(2, c);
  return 0;
}
