#include <bits/stdc++.h>
using namespace std;
int main() {
  double n, m;
  vector<double> C(5);
  cin >> n >> m;
  for (int i = 1; i <= 5; i++) {
    int z = 5 - i;
    C[i - 1] = 0;
    if (z == 0) z = 5;
    for (double j = z; j <= m; j += 5) {
      C[i - 1]++;
    }
  }
  long long R = 0;
  for (double i = 1; i <= n; i++) {
    if (i > 5) {
      i = 1;
      n -= 5;
    }
    R += C[i - 1];
  }
  cout << R << endl;
  return 0;
}
