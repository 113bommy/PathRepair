#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
vector<int> acomp;
double get(double mid) {
  double ans1 = INT_MIN;
  double ans2 = INT_MIN;
  double sum1 = 0;
  double sum2 = 0;
  for (int i = 0; i < a.size(); i++) {
    sum1 = sum1 + a[i] - mid;
    sum2 = sum2 + acomp[i] + mid;
    if (sum1 > ans1) {
      ans1 = sum1;
    }
    if (sum2 > ans2) {
      ans2 = sum2;
    }
    if (sum1 < 0) {
      sum1 = 0;
    }
    if (sum2 < 0) {
      sum2 = 0;
    }
  }
  return max(ans1, ans2);
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
    acomp.push_back(-x);
  }
  double l = -1e9;
  double r = 1e9;
  while (r - l > 1e-11) {
    double mid1 = (r + 2 * l) / 3;
    double mid2 = (l + 2 * r) / 3;
    double val1 = get(mid1);
    double val2 = get(mid2);
    if (val1 > val2) {
      l = mid1;
    } else {
      r = mid2;
    }
  }
  printf("%0.12lg\n", min(get(l), get(r)));
}
