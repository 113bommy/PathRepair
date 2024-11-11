#include <bits/stdc++.h>
using namespace std;
int gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<long long> v(n);
  for (int(i) = int(0); i < int(n); i++) cin >> v[i];
  for (int(i) = int(0); i < int(n); i++) {
    while (v[i] % 2 == 0) v[i] /= 2;
    while (v[i] % 3 == 0) v[i] /= 3;
  }
  if (unique(v.begin(), v.end()) == v.begin())
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
