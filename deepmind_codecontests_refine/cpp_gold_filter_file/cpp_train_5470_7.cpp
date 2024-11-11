#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return ((a * b) / gcd(a, b)); }
bool RPrime(int a, int b) {
  if (gcd(a, b) == 1)
    return true;
  else
    return false;
}
int main() {
  long long int n, i, a[1001], count = 0;
  vector<long long int> v;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (i = 0; i < n - 1; ++i) {
    v.push_back(a[i]);
    if (!RPrime(a[i], a[i + 1])) {
      ++count;
      v.push_back(1);
    }
  }
  v.push_back(a[n - 1]);
  cout << count << endl;
  for (i = 0; i < v.size(); ++i) cout << v[i] << " ";
}
