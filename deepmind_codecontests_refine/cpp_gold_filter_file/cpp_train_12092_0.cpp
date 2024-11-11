#include <bits/stdc++.h>
using namespace std;
long long int n, k, a, b;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int dist(long long int st, long long int en) {
  if (en >= st)
    return (n * k) / gcd(n * k, en - st);
  else
    return (n * k) / gcd(n * k + (en - st), n * k);
}
long long int maxans = 0LL;
long long int minans = 100000000000000LL;
void func(long long int s) {
  for (int i = 0; i < n; i++) {
    long long int e1 = k * i + b + 1;
    long long int e2 = k * i + k + 1 - b;
    maxans = max(maxans, dist(s, e1));
    maxans = max(maxans, dist(s, e2));
    minans = min(minans, dist(s, e1));
    minans = min(minans, dist(s, e2));
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  ;
  cin >> n >> k >> a >> b;
  long long int s1 = 1 + a;
  long long int s2 = k - a + (n - 1) * k + 1;
  if (s2 > n * k) s2 -= n * k;
  func(s1);
  func(s2);
  cout << minans << ' ' << maxans << endl;
  return 0;
}
