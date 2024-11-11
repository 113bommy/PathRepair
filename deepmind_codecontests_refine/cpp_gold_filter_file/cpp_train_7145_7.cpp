#include <bits/stdc++.h>
using namespace std;
int* num_to_bit(long long n, int k) {
  stack<int> second;
  static int a[65] = {0};
  int i = 0;
  while (n > 0) {
    int m = n % k;
    a[i] = m;
    i++;
    second.push(m);
    n /= k;
  }
  return a;
}
int bit(long long n) {
  int c = 0;
  if (n == 0)
    return 1;
  else {
    while (n != 0) {
      c++;
      n /= 2;
    }
    return c;
  }
}
void ans_nikalo() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, l;
  cin >> n >> l;
  long long a[n];
  vector<pair<long long, long long>> v;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    if (2 * a[i] < a[i + 1]) {
      a[i + 1] = min(2 * a[i], a[i + 1]);
    }
  }
  long long ans = LLONG_MAX;
  long long sum = 0;
  for (int i = n - 1; i >= 0; i--) {
    long long m = pow(2, i);
    long long q = l / m;
    long long r = l % m;
    l -= q * m;
    sum += a[i] * q;
    ans = min(ans, sum + (l > 0) * a[i]);
  }
  cout << ans;
  return;
}
int main() {
  ans_nikalo();
  return 0;
}
