#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long double vb, vs, t_run, t_bus = 0, t_total, x, y, mn = INT_MAX, ind;
  cin >> n >> vb >> vs;
  double arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  cin >> x >> y;
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      t_run = (sqrt(pow(arr[i] - x, 2) + pow(y, 2))) / vs;
      t_bus += (arr[i] - arr[i - 1]) / vb;
      t_total = t_run + t_bus;
      if (t_total <= mn) {
        ind = i + 1;
        mn = t_total;
      }
    }
  }
  cout << ind << endl;
  return 0;
}
