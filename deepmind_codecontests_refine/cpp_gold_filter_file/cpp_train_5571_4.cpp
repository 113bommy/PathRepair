#include <bits/stdc++.h>
using namespace std;
int n, a[100100], l = 1, ax, an, f = 1, i;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  ax = a[1];
  an = a[1];
  long long sum = 1;
  for (int i = 1; i <= n; i++) {
    if (i == 1) continue;
    if (a[i] != a[i - 1]) {
      if (abs(ax - a[i]) <= 1 && abs(an - a[i]) <= 1) {
        if (ax < a[i]) ax = a[i];
        if (an > a[i]) an = a[i];
        l = i;
      } else if (abs(a[i] - a[i - 1]) == 1) {
        ax = max(a[i], a[i - 1]);
        an = min(a[i], a[i - 1]);
        f = l;
        l = i;
      } else {
        f = i;
        l = i;
        ax = a[i];
        an = a[i];
      }
    }
    if ((i - f) + 1 > sum) sum = (i - f) + 1;
  }
  cout << sum;
}
