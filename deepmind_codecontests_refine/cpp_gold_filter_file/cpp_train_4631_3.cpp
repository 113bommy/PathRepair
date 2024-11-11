#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v;
  long long x, z;
  cin >> x;
  while (x) {
    if (x == 9)
      v.push_back(x);
    else {
      z = min((x % 10), (9 - (x % 10)));
      v.push_back(z);
    }
    x /= 10;
  }
  for (int i = v.size() - 1; i >= 0; i--) cout << v[i];
  return 0;
}
