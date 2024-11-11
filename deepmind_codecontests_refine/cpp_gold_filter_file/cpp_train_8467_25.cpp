#include <bits/stdc++.h>
using namespace std;
long long int max3(long long int a, long long int b, long long int c) {
  long long int x = max(a, b);
  long long int x1 = max(x, c);
  return x1;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
bool val(int x, int l, int r) { return l <= x && x <= r; }
long long int dp[2001][2001];
long long int a[20001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  t = 1;
  while (t--) {
    long long int n;
    cin >> n;
    cout << 0 << " " << 0 << " " << n << endl;
  }
}
