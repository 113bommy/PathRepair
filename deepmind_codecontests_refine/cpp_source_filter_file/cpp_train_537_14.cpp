#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}
int asum(long long int a[], long long int n) {
  long long int sum = 0;
  for (long long int i = 0; i < n; i++) sum += a[i];
  return sum;
}
long long int bin(long long int n) {
  long long int B_Number = 0;
  long long int cnt = 0;
  while (n != 0) {
    long long int rem = n % 2;
    long long int c = pow(10, cnt);
    B_Number += rem * c;
    n /= 2;
    cnt++;
  }
  return B_Number;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
bool is_prime(long long int x) {
  if (x == 1) return false;
  if (x == 2 || x == 3) return true;
  for (long long int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k, d, ans = INT_MAX;
    cin >> n >> k >> d;
    ;
    long long int a[n];
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
    };
    for (long long int i = 0; i < n - d + 1; i++) {
      set<long long int> s;
      for (long long int j = 0; j < d; j++) {
        s.insert(a[j]);
      }
      if (ans > s.size()) {
        ans = s.size();
      }
    }
    cout << ans << endl;
  }
  return 0;
}
