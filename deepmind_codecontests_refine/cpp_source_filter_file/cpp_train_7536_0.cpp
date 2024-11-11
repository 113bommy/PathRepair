#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  for (;;) {
    if (a == 0) return b;
    b %= a;
    if (b == 0) return a;
    a %= b;
  }
}
long long ls[100013] = {0}, rs[100013] = {0};
int main() {
  vector<int> a;
  int n;
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ls[0] = 0;
  rs[n - 1] = 0;
  long long sum = 0;
  sort(a.begin(), a.end());
  for (int i = 1; i < n; i++) {
    long long temp = ls[i - 1] + ((abs(a[i] - a[i - 1])) * (i - 1));
    sum = 0;
    sum = sum + (temp + abs(a[i] - a[i - 1]));
    ls[i] = sum;
  }
  sum = 0;
  for (int i = n - 2; i >= 0; i--) {
    sum = 0;
    long long temp = rs[i + 1] + ((abs(a[i] - a[i + 1]) * (n - (i + 2))));
    sum = temp + (abs(a[i] - a[i + 1]));
    rs[i] = sum;
  }
  sum = 0;
  for (int i = 0; i < n; i++) {
    sum = sum + ls[i] + rs[i] + a[i];
  }
  cout << sum / gcd(sum, n) << " " << n / gcd(sum, n);
  return 0;
}
