#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;
long long max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
long long min(long long a, long long b) {
  if (a < b)
    return a;
  else
    return b;
}
const int MAXC = 1e5;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      long long a;
      cin >> a;
      sum += a;
    }
    if (sum == m)
      cout << "YES" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
