#include <bits/stdc++.h>
using namespace std;
bool fit(int a, int b, int n, int m) {
  if ((a <= n && b <= m))
    return true;
  else
    return false;
}
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int xi[n], yi[n];
  for (int i = 0; i < n; i++) {
    cin >> xi[i] >> yi[i];
  }
  int result = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (fit(xi[i], yi[i], a, b)) {
        int recaa = a - xi[i];
        int recab = b;
        int recba = b - yi[i];
        int recbb = a;
        if (fit(xi[j], yi[j], recaa, recab) ||
            fit(yi[j], xi[j], recaa, recab) ||
            fit(xi[j], yi[j], recba, recbb) ||
            fit(yi[j], xi[j], recba, recbb)) {
          result = max(result, xi[i] * yi[i] + xi[j] * yi[j]);
        }
      }
      if (fit(yi[i], xi[i], a, b)) {
        int recaa = a - yi[i];
        int recab = b;
        int recba = b - xi[i];
        int recbb = a;
        if (fit(xi[j], yi[j], recaa, recab) ||
            fit(yi[j], xi[j], recaa, recab) ||
            fit(xi[j], yi[j], recba, recbb) ||
            fit(yi[j], xi[j], recba, recbb)) {
          result = max(result, xi[i] * yi[i] + xi[j] * yi[j]);
        }
      }
    }
  }
  cout << result;
  return 0;
}
