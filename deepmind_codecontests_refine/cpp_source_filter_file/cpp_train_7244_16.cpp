#include <bits/stdc++.h>
using namespace std;
const int n = 250;
double E(const vector<int>& a) {
  double ans = 0;
  for (int x : a) ans += x;
  return ans / a.size();
}
int main() {
  int N;
  for (scanf("%d", &N); N > 0; N--) {
    vector<int> a(n);
    int r = 0;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), r = max(r, a[i]);
    double m = E(a);
    int cnt = 0;
    for (int x : a)
      if (abs(x) > r / 2) cnt++;
    if (cnt < 50)
      printf("poisson\n");
    else
      printf("uniform\n");
  }
}
