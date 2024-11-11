#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  scanf("%d", &N);
  int Z[N + 1];
  Z[0] = 1000;
  for (int i = 0; i < (N); i++) scanf("%d", &Z[i + 1]);
  bool flag = true;
  for (int i = 1; i <= N; i++) {
    vector<int> V;
    int T[4];
    T[0] = (Z[i] / 1000) * 1000;
    Z[i] %= 1000;
    T[1] = (Z[i] / 100) * 100;
    Z[i] %= 100;
    T[2] = (Z[i] / 10) * 10;
    Z[i] %= 10;
    T[3] = Z[i];
    Z[i] = T[0] + T[1] + T[2] + T[3];
    for (int k = 0; k < (10); k++) {
      V.push_back(Z[i] - T[0] + k * 1000);
      V.push_back(Z[i] - T[1] + k * 100);
      V.push_back(Z[i] - T[2] + k * 10);
      V.push_back(Z[i] - T[3] + k);
    }
    sort(V.begin(), V.end());
    int k = 0;
    while ((k < V.size()) && (V[k] < Z[i - 1])) k++;
    if (k == V.size())
      flag = false;
    else
      Z[i] = V[k];
  }
  if ((!flag) || (Z[N] > 2011))
    printf("No solution\n");
  else {
    for (int i = 1; i <= N; i++) printf("%d\n", Z[i]);
  }
}
