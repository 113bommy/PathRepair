#include <bits/stdc++.h>
using namespace std;
typedef struct {
  int x;
  int y;
  int z;
} T1;
T1 V[5010];
double D[5010][5010];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> V[i].x >> V[i].y >> V[i].z;
    for (int j = 0; j < i; j++)
      D[j][i] = D[i][j] = sqrt(double((V[i].x - V[j].x) * (V[i].x - V[j].x) +
                                      (V[i].y - V[j].y) * (V[i].y - V[j].y) +
                                      (V[i].z - V[j].z) * (V[i].z - V[j].z)));
  }
  double minP = D[0][1] + D[1][2] + D[2][0];
  for (int i = 1; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      minP = min(minP, D[0][i] + D[i][j] + D[j][0]);
  cout.precision(10);
  cout << minP / 2.0;
  return 0;
}
