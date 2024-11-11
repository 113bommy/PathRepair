#include <bits/stdc++.h>
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
long long int sqr(long long int n) { return n * n; }
bool isPerfectSquare(long double x) {
  long double sr = sqrt(x);
  return ((sr - floor(sr)) == 0);
}
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<long long int> v;
    v.push_back(a % 2);
    v.push_back(b % 2);
    v.push_back(c % 2);
    v.push_back(d % 2);
    sort(v.begin(), v.end());
    long long int i = 0;
    while (!v[i]) {
      i++;
    }
    long long int ans = 4 - i;
    if (ans == 0 || ans == 4 || ans == 1) {
      cout << "Yes" << endl;
    } else if (ans == 3) {
      if (!a || !b || !c) {
        cout << "No" << endl;
      } else {
        cout << "Yes" << endl;
      }
    } else {
      cout << "No" << endl;
    }
  }
}
