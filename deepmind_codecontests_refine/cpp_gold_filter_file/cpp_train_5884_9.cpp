#include <bits/stdc++.h>
using namespace std;
long long a, b, x1, x2;
long long ans;
int main() {
  cin >> a >> b;
  vector<long long> v;
  for (int i = 2; i < 63; i++) {
    for (int j = 0; j + 1 < i; j++) {
      v.push_back((1ll << i) - 1 - (1ll << j));
    }
  }
  sort(v.begin(), v.end());
  x1 = lower_bound(v.begin(), v.end(), a) - v.begin();
  x2 = upper_bound(v.begin(), v.end(), b) - v.begin();
  cout << x2 - x1 << endl;
  return 0;
}
