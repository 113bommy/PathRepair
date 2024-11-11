#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, r;
  scanf("%d%d", &l, &r);
  vector<long long> v;
  long long pr = 1;
  for (int i = 0; i < 31; ++i) {
    if (i != 0) pr *= 2;
    long long loc = pr;
    for (int j = 0; j < 31; ++j) {
      if (j != 0) loc *= 3;
      if (loc > 2 * 1e9) break;
      v.push_back(loc);
    }
  }
  sort(v.begin(), v.end());
  cout << lower_bound(v.begin(), v.end(), r) -
              lower_bound(v.begin(), v.end(), l);
  return 0;
}
