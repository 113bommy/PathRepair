#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long gcdVec(vector<long long> vec) {
  long long res = vec[0];
  for (int i = 1; i < vec.size(); i++) {
    res = gcd(res, vec[i]);
    if (res == 1) {
      return 1;
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long ttt;
  cin >> ttt;
  while (ttt--) {
    long long n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cout << 2 << " ";
    }
    cout << "\n";
  }
  return 0;
}
