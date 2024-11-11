#include <bits/stdc++.h>
using namespace std;
int main() {
  double s, a, b, c;
  while (cin >> s >> a >> b >> c) {
    double sum = a + b + c;
    if (sum < 1e-9)
      cout << 0 << " " << 0 << " " << 0 << endl;
    else {
      double pa = a / sum;
      double push_back = b / sum;
      double pc = c / sum;
      printf("%.8lf %.8lf %.8lf\n", pa * s, push_back * s, pc * s);
    }
  }
  return 0;
}
