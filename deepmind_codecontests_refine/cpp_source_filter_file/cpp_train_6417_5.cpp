#include <bits/stdc++.h>
using namespace std;
int sum(long int k) {
  int ans = 0;
  while (k > 0) {
    ans += (k % 10);
    k /= 10;
  }
  return ans;
}
int main() {
  long int i, k;
  vector<long long int> v;
  for (i = 1; i < 10001; i++) {
    if (10 - sum(i) >= 0) v.push_back(10 * i + 10 - sum(i));
  }
  cin >> k;
  cout << v[k - 1] << "\n";
}
