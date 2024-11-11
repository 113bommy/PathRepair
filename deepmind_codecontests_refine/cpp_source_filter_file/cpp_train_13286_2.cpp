#include <bits/stdc++.h>
using namespace std;
long long c(long long n, long long k) {
  long long numerator = 1;
  long long i;
  vector<int> v(k - 1);
  for (i = 0; i < v.size(); i++) v[i] = i + 2;
  for (i = 0; i < k; i++) {
    numerator = (numerator * (n - i));
    for (int j = 0; j < k - 1; j++)
      if (numerator % v[j] == 0) numerator /= v[j], v[j] = 1;
  }
  return numerator;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, k, i, a[5];
  a[1] = 0;
  a[2] = 1;
  a[3] = 2;
  a[4] = 9;
  cin >> n >> k;
  long long sum = 0;
  for (i = n - k; i < n; i++) {
    sum += c(n, i) * a[n - i];
  }
  cout << sum + 1 << endl;
  return 0;
}
