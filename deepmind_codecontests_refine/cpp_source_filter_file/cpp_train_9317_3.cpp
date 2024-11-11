#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return b * a / gcd(a, b);
}
long long int abs1(long long int a) {
  if (a < 0)
    return -1 * a;
  else
    return a;
}
long long int max(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
const double PI = 3.14159265358979323846;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  long long int r = n;
  vector<int> v;
  while (n % 2 == 0) {
    v.push_back(2);
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      v.push_back(1);
      n = n / i;
    }
  }
  if (n > 2) v.push_back(n);
  sort(v.begin(), v.end());
  cout << r << " ";
  for (int i = 0; i < v.size(); i++) {
    r = r / v[i];
    cout << r << " ";
  }
  return 0;
}
