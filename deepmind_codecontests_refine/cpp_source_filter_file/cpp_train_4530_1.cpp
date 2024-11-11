#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, iR, iV;
  scanf("%d%d%d", &N, &iR, &iV);
  const double R = iR, V = iV;
  const double circunf = 2.0 * M_PI * R;
  const double period = circunf / V;
  for (int i = 0; i < (int)(N); i++) {
    int si, fi;
    scanf("%d%d", &si, &fi);
    const double L = fi - si;
    const long long vueltas = L / circunf;
    const double Lr = L - vueltas * circunf;
    double trA = 0.0, trB = period;
    for (int k = 0; k < (int)(50); k++) {
      const double trC = 0.5 * (trA + trB);
      const double x = V * trC + 2.0 * R * sin(0.5 * V / R * trC);
      if (x < Lr)
        trA = trC;
      else
        trB = trC;
    }
    const double tr = (trA + trB) * 0.5;
    const double totalT = vueltas * period + tr;
    printf("%.15lf\n", totalT);
  }
  return 0;
}
