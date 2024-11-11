#include <bits/stdc++.h>
using namespace std;
int maxint = numeric_limits<int>::max();
bool sortbysec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  return (a.second > b.second);
}
bool sortbyfirst(const pair<long long int, long long int> &a,
                 const pair<long long int, long long int> &b) {
  return (a.first < b.first);
}
long double distance1(long long int x1, long long int y1, long long int x2,
                      long long int y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}
long long binpoww(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long int fast_power(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
void solve() {
  long long int n, k;
  cin >> n >> k;
  long long int a[n];
  map<long long int, long long int> ma;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    ma[a[i]]++;
  }
  long long int s = 0;
  sort(a, a + n);
  if (n == 1) {
    cout << n;
    return;
  }
  for (long long int i = 0; i < n; i++) {
    if (ma[a[i] * k] == 1 && ma[a[i]] == 1) {
      ma[a[i] * k] = 0;
      s++;
    }
  }
  cout << n - s;
}
int main() {
  ios_base::sync_with_stdio(false);
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
