#include <bits/stdc++.h>
using namespace std;
double ans, k, b, n, t;
int main() {
  int i, j;
  cin >> k >> b >> n >> t;
  if (k == 1) {
    long long int pre = 1;
    for (i = 0; i < n; i++) pre = pre * k + b;
    int count = 0;
    while (t < pre) {
      t = t * k + b;
      count++;
    }
    cout << count << endl;
    return 0;
  }
  double val = n * log10(k) + log10((k - 1 + b) / (t * (k - 1) + b));
  val = val / log10(k);
  if (val <= 0) val = 0;
  int ans;
  if ((val - floor(val)) < 0.000000001)
    ans = (int)val;
  else
    ans = ceil(val);
  cout << ans << endl;
  return 0;
}
