#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int n, a, d;
  cin >> n >> a >> d;
  int t, v;
  double T, P = 0, D;
  while (n--) {
    cin >> t >> v;
    T = 1.0 * v / a;
    if (T * v <= 2 * d) {
      D = (1.0 * d - T * v * 0.5) / v;
      T = T + D;
    } else {
      T = 2.0 * d / a;
    }
    T += t;
    if (T < P) T = P;
    printf("%.7f\n", T);
    P = T;
  }
  return EXIT_SUCCESS;
}
