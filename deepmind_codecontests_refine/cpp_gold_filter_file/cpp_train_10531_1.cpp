#include <bits/stdc++.h>
using namespace std;
long long int mod = 998244353;
long long int gcdExtended(long long int a, long long int b, long long int *x,
                          long long int *y);
long long int modInverse(long long int a, long long int m) {
  long long int x, y;
  long long int g = gcdExtended(a, m, &x, &y);
  if (g != 1)
    cout << "Inverse doesn't exist";
  else {
    long long int res = (x % m + m) % m;
    return res;
  }
}
long long int gcdExtended(long long int a, long long int b, long long int *x,
                          long long int *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  long long int x1, y1;
  long long int gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
void solve() {
  int n;
  cin >> n;
  int x;
  cin >> x;
  map<int, int> vaibhav;
  int l = pow(2, n);
  vector<int> A;
  int dop = 0;
  vaibhav[0] = 1;
  int yo = 33;
  while (yo--) {
    for (int i = 1; i < l; i++) {
      if (vaibhav[dop ^ x ^ i] != 1 && vaibhav[dop ^ i] != 1) {
        dop ^= i;
        A.push_back(i);
        vaibhav[dop] = 1;
      }
    }
  }
  cout << A.size() << "\n";
  for (int i = 0; i < A.size(); i++) {
    cout << A[i] << " ";
  }
}
int main() {
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
