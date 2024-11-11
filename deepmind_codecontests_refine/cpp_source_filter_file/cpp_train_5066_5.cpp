#include <bits/stdc++.h>
using namespace std;
int main() {
  int count_ob, count_pisem;
  long long d;
  cin >> count_ob >> count_pisem;
  vector<int> as = {0};
  for (int i = 0; i < count_ob; ++i) {
    cin >> d;
    d += as.back();
    as.push_back(d);
  }
  for (int i = 0; i < count_pisem; ++i) {
    cin >> d;
    int l = 0, r = as.size();
    while (r > l) {
      int m = (l + r) / 2;
      if (as[m] >= d) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    cout << l << " " << d - as[l - 1] << '\n';
  }
  return 0;
}
