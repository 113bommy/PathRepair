#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  double N, M;
  cin >> N >> M;
  if (N == 1) {
    printf("%lf\n", 1.0);
    return 0;
  }
  if (M == 1) {
    printf("%lf\n", 1.0 / N);
    return 0;
  }
  N = 1 / N + ((N - 1) / N) * (M - 1) / (N * M - 1);
  printf("%lf\n", N);
}
