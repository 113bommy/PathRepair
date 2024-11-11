#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, d;
  cin >> r >> d;
  int n;
  cin >> n;
  int x, y, R, t = 0;
  while (n--) {
    cin >> x >> y >> R;
    double a = sqrt(x * x + y * y);
    if (a + R <= r)
      if (a - R >= r - d) t++;
  }
  cout << t << endl;
}
