#include <bits/stdc++.h>
using namespace std;
const double gen3 = sqrt(3.0), gen3_2 = gen3 / 2;
int n, m;
long long calc() {
  long long ans = 0;
  for (int i = m + 1; i + m <= n && i <= (n + 1) / 2; ++i) {
    double xi = i * 0.5, yi = i * gen3_2;
    int sum = 0;
    for (int j = m + 1, k = n - m; j + m <= n; ++j) {
      double xj = (n + j + 1) * 0.5, yj = (n - j + 1) * gen3_2;
      double val = (xj - xi) * (k - xi) - (yj - yi) * yi;
      while (k > m && val >= 1e-10) val -= xj - xi, --k;
      if (k == m) break;
      sum += k - m;
    }
    if (i * 2 != (n + 1)) sum *= 2;
    ans += sum;
  }
  return ans * 3;
}
int main() {
  scanf("%d %d", &n, &m);
  cout << calc() << endl;
  return 0;
}
