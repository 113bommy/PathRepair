#include <bits/stdc++.h>
using namespace std;
int s, a, b, c;
int main() {
  int i, j;
  cin >> s >> a >> b >> c;
  if (a + b + c == 0) {
    cout << s << " " << 0 << " " << 0 << endl;
    return 0;
  }
  double t = s * 1.0 / (a + b + c);
  printf("%.10lf %.10lf %.10lf\n", t * a, t * b, t * c);
  return 0;
}
