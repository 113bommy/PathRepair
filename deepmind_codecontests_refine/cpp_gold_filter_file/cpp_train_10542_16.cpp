#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<long long> xR(n, 0), yR(n, 0), xB(m, 0), yB(m, 0);
  vector<vector<int> > S(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) scanf("%I64d%I64d", &xR[i], &yR[i]);
  for (int i = 0; i < m; i++) scanf("%I64d%I64d", &xB[i], &yB[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (xR[i] < xR[j]) {
        long long a = yR[i] - yR[j];
        long long b = xR[j] - xR[i];
        long long c = -a * xR[i] - b * yR[i];
        for (int k = 0; k < m; k++) {
          if (xB[k] > xR[i] && xB[k] <= xR[j] && a * xB[k] + b * yB[k] + c >= 0)
            S[i][j]++;
        }
        S[j][i] = -S[i][j];
      }
  long long count = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      for (int k = j + 1; k < n; k++) {
        if (S[i][j] + S[j][k] + S[k][i] == 0) count++;
      }
  cout << count;
}
