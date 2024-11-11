#include <bits/stdc++.h>
using namespace std;
const int MAX = 10001;
void solve() {}
int main() {
  int a, b, c, s;
  while (cin >> s >> a >> b >> c) {
    if (a + b + c == 0) {
      puts("0.0 0.0 0.0");
    } else {
      double t = a + b + c;
      double x = a / t * s;
      double y = b / t * s;
      double z = c / t * s;
      printf("%.10lf %.10lf %.10lf\n", x, y, z);
    }
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
