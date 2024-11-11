#include <bits/stdc++.h>
using namespace std;
const int M = 100 + 5;
struct NODE {
  long long int x;
  long long int y;
  double p;
} node[M];
int main() {
  int n;
  cin >> n;
  int N = n;
  int k, epsilon;
  cin >> k >> epsilon;
  int K = k;
  long long int x0, y0;
  cin >> x0 >> y0;
  for (int i = 0; i < n; i++) {
    cin >> node[i].x >> node[i].y;
  }
  int num = 0;
  double R_L = 0;
  double R_R = 4000;
  while (num < 50) {
    double R_M = (R_R + R_L) / 2;
    for (int i = 0; i < n; i++) {
      long long int D2 = (node[i].x - x0) * (node[i].x - x0) +
                         (node[i].y - y0) * (node[i].y - y0);
      if (D2 <= R_M * R_M) {
        node[i].p = 1;
      } else {
        node[i].p =
            pow(2.7182818284590452353602874713527, 1 - 1.0 * D2 / (R_M * R_M));
      }
    }
    double Pr[M][M];
    for (int row = 0; row <= N; row++) {
      for (int col = 0; col <= N; col++) {
        Pr[row][col] = 0;
      }
    }
    Pr[0][0] = 1;
    for (int row = 1; row <= N; row++) {
      for (int col = 0; col <= N; col++) {
        double p1 = 0;
        double p2 = 0;
        if (row - 1 >= 0 && col - 1 >= 0) {
          p1 = Pr[row - 1][col - 1] * node[row - 1].p;
        }
        if (row - 1 >= 0) {
          p2 = Pr[row - 1][col] * (1 - node[row - 1].p);
        }
        Pr[row][col] = p1 + p2;
      }
    }
    double P_success = 0;
    for (int col = K; col <= N; col++) {
      P_success += Pr[N][col];
    }
    if (P_success >= 1 - 1.0 * epsilon / 1000) {
      R_R = R_M;
    } else {
      R_L = R_M;
    }
    num++;
  }
  printf("%.10f\n", R_L);
  return 0;
}
