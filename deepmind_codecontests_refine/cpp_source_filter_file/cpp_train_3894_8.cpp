#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const double eps = 1e-9;
const double pi = acos(-1.0);
int main() {
  vector<int> a(3);
  for (int i = 0; i < 3; i++) scanf("%d", &a[i]);
  sort(a.begin(), a.end());
  int mini = a[0] + (a[1] - a[0]) / 3 + (a[2] - a[0]) / 3;
  if (a[0] > 0) {
    a[0]--;
    mini = min(mini, a[0] + (a[1] - a[0]) / 3 + (a[2] - a[0]) / 3);
    if (a[0] > 0) {
      a[0]--;
      mini = min(mini, a[0] + (a[1] - a[0]) / 3 + (a[2] - a[0]) / 3);
    }
  }
  cout << mini << endl;
  return 0;
}
