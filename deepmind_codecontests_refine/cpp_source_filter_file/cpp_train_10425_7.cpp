#include <bits/stdc++.h>
using namespace std;
bool sortbysecdesc(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second > b.second;
}
bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
int findGCD(long long a[], long long n) {
  int result = a[0];
  for (int i = 1; i < n; i++) {
    result = gcd(a[i], result);
    if (result == 1) {
      return 1;
    }
  }
  return result;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long n, x, y;
  cin >> n >> x >> y;
  n /= 2;
  if (x == n || x == n + 1 || y == n || y == n + 1)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
