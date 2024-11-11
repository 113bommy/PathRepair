#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-100;
long double p, k, b, fb;
vector<long long> ans;
bool equal(long long m, double n) {
  if (fabs((double)m - n) <= eps) return true;
  return false;
}
int main() {
  cin >> p >> k;
  b = -p / k;
  if (equal((long long)b, b) == true)
    b = (long long)b;
  else
    b = floor(b + 1);
  ans.push_back((long long)(k * b + p));
  bool ok = false;
  for (int i = 1; i <= 1e7; i++) {
    fb = b;
    b = -b / k;
    if (equal((long long)b, b) == true)
      b = (long long)b;
    else
      b = floor(b + 1);
    ans.push_back((long long)(k * b + fb));
    if (equal(0, b) == true) {
      ok = true;
      break;
    }
  }
  if (ok == false)
    printf("-1");
  else {
    while (ans.back() == 0) ans.pop_back();
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
  }
  return 0;
}
