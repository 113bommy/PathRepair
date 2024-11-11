#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  int ind = 0;
  int d = 1;
  while (sum > 0) {
    if (a[ind] > 0) {
      printf("P");
      a[ind]--;
      sum--;
    }
    if (ind + d < 0 || ind + d >= n) {
      d = -d;
    }
    ind = ind + d;
    printf(d == 1 ? "R" : "L");
  }
}
