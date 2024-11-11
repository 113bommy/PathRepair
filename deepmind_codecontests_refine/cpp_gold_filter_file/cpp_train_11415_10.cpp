#include <bits/stdc++.h>
using namespace std;
vector<int> v;
long long my_pow(int x, int n) {
  long long res = 1;
  while (n) {
    if (n & 1) res *= x;
    x *= x;
    n >>= 1;
  }
  return res;
}
void init() {
  v.clear();
  double ln2 = log10(2.0), ln3 = log10(3.0);
  int maxm = 9.0 / ln2 + 1;
  int maxn = (9.0 + ln2) / ln3;
  for (int m = 0; m <= maxm; m++) {
    for (int n = 0; n <= maxn; n++) {
      if (ln2 * (double)m + ln3 * (double)n <= 9.0 + ln2)
        v.push_back(my_pow(2, m) * my_pow(3, n));
    }
  }
  sort(v.begin(), v.end());
}
int main() {
  int l, r;
  init();
  while (cin >> l >> r) {
    cout << upper_bound(v.begin(), v.end(), r) -
                upper_bound(v.begin(), v.end(), l - 1)
         << endl;
  }
  return 0;
}
