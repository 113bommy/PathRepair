#include <bits/stdc++.h>
using namespace std;
vector<double> vec;
int main() {
  int n;
  cin >> n;
  vec.resize(n);
  for (int i = 0; i < n; i++) cin >> vec[i];
  sort(vec.rbegin(), vec.rend());
  double res = 0.0;
  if (vec[0] == 1.0) {
    res = 1.0;
  } else {
    for (int i = 0; i < n; i++) {
      double sum = 0;
      for (int j = 0; j <= i; j++) {
        double mul = vec[j];
        for (int k = 0; k <= i; k++) {
          if (k != j) mul *= 1 - vec[k];
        }
        sum += mul;
      }
      res = max(res, sum);
    }
  }
  printf("%.20lf", res);
}
