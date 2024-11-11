#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int a, b;
  cin >> a >> b;
  if (a < b) swap(a, b);
  vector<int> v;
  v.push_back(1);
  vector<int>::iterator it1, it2;
  for (int i = 1; i * i <= a; i++) {
    if (a % i == 0) {
      if (b % i == 0) v.push_back(i);
      if (b % (a / i) == 0 && i * i != a) v.push_back(a / i);
    }
  }
  sort(v.begin(), v.end());
  int t, l, r;
  cin >> t;
  while (t--) {
    cin >> l >> r;
    it1 = lower_bound(v.begin(), v.end(), l);
    if ((*it1) <= r && it1 != v.end()) {
      it2 = upper_bound(v.begin(), v.end(), r);
      cout << *(it2 - 1) << endl;
    } else
      cout << "-1" << endl;
  }
  return 0;
}
