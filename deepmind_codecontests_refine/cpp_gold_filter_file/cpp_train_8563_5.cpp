#include <bits/stdc++.h>
using namespace std;
long long int base(int a, int b) {
  int ret = 0;
  vector<int> v;
  while (a > 0) {
    v.push_back(a % b);
    a /= b;
  }
  for (int i = 0; i < v.size(); i++) {
    ret += v[i];
  }
  return ret;
}
int main() {
  long long int a;
  cin >> a;
  long long int ans = 0;
  long long int k = 0;
  for (long long int i = 2; i < a; i++) {
    ans += base(a, i);
  }
  k = a - 2;
  for (int i = 2; i < k; i++) {
    while (ans % i == 0 && k % i == 0) {
      ans /= i;
      k /= i;
    }
  }
  cout << ans << "/" << k;
}
