#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n) {
  return n == 0 ? m : gcd(n, m % n);
}
long long int a[1002];
vector<long long int> v;
int main() {
  long long int n, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int j = 0;
  long long int k;
  long long int cnt = 0;
  for (i = 0; i < n - 1; i++) {
    v.push_back(a[i]);
    if (gcd(a[i], a[i + 1]) != 1) {
      for (j = 1;; j++) {
        if (gcd(a[i], j) == 1 && gcd(a[i + 1], j) == 1) {
          v.push_back(j);
          cnt++;
          break;
        }
      }
    }
  }
  v.push_back(a[n - 1]);
  cout << cnt << endl;
  for (i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  return 0;
}
