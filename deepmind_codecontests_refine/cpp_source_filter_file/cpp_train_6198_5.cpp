#include <bits/stdc++.h>
using namespace std;
int M[17], R[17], n, sum;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> M[i];
  for (int i = 1; i <= n; i++) cin >> R[i];
  for (int i = 1; i <= 72019; i++)
    for (int j = 1; j <= n; j++) {
      if (i % M[j] == R[j]) {
        sum++;
        break;
      }
    }
  double ans = 1.0 * sum / 720720;
  printf("%.6lf", ans);
}
