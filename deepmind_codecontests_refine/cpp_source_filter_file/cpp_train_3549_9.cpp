#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int p;
  cin >> p;
  int a[n + 1];
  int b[n + 1];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  if (a[0] == 0 || b[0] == 1) {
    cout << -1 << endl;
    return 0;
  }
  double ans = p + p / ((double)b[0] - 1);
  for (int i = n - 1; i >= 1; i--) {
    if (a[i] == 1 || b[i] == 1) {
      cout << -1 << endl;
      return 0;
    }
    ans = ans + ans / ((double)a[i] - 1);
    ans = ans + ans / ((double)b[i] - 1);
  }
  ans = ans + ans / ((double)a[0] - 1);
  printf("%0.10lf\n", ans - p);
  return 0;
}
