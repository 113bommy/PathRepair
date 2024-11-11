#include <bits/stdc++.h>
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
#pragma ide diagnostic ignored "UnusedImportStatement"
using namespace std;
class B {
 public:
  B() {
    int n, T, m;
    double A[2 * 100000];
    double MEAN[2 * 100000];
    double c;
    scanf("%d%d%lf", &n, &T, &c);
    double mean = 0.0;
    for (int i = 0; i < n; i++) {
      scanf("%lf", &A[i]);
      mean = (mean + double(A[i]) / T) / c;
      MEAN[i] = mean;
      if (i != 0) {
        A[i] += A[i - 1];
      }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      int p;
      scanf("%d", &p);
      p--;
      double real = double(A[p] - (p >= T ? A[p - T] : 0)) / T;
      double approx = MEAN[p];
      double error = fabs(approx - real) / real;
      printf("%.9lf %.9lf %.9lf\n", real, approx, error);
    }
  }
};
int main(int argc, const char* argv[]) {
  new B();
  return 0;
}
