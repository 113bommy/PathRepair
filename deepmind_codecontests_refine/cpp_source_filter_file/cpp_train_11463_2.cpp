#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b) {
  long long int res = 1;
  a = a % 1000000007;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % 1000000007;
      b--;
    }
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  return (b == 0) ? a : gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int a, b;
  cin >> a >> b;
  long long int x = 0;
  while (x * (x + 1) / 2 <= (a + b)) x++;
  x--;
  vector<long long int> bb;
  vector<long long int> aa;
  set<long long int> ac;
  for (long long int i = x; i > 0; i--) {
    if (x <= a) {
      aa.push_back(x);
      ac.insert(x);
      a -= x;
    } else {
      if (a > 0) {
        aa.push_back(a);
        ac.insert(a);
      }
      break;
    }
  }
  cout << aa.size() << "\n";
  for (auto i : ac) cout << i << " ";
  cout << "\n";
  for (long long int i = x; i > 0; i--) {
    if (ac.find(i) == ac.end()) bb.push_back(i);
  }
  cout << bb.size() << "\n";
  for (auto i : bb) cout << i << " ";
}
