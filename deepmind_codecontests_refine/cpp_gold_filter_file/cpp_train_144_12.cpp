#include <bits/stdc++.h>
using namespace std;
long double PI = acosl(-1);
bool compare_int(int a, int b) { return (a > b); }
bool compare_string(string a, string b) { return a.size() < b.size(); }
bool compare_pair(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
long long int fact(long long int n) {
  if (n == 0 || n == 1)
    return 1;
  else
    return n * fact(n - 1);
}
bool check(int n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, c, x;
  cin >> n >> c;
  vector<int> a;
  for (int i = 0; i < n; i++) cin >> x, a.push_back(x);
  int ans = INT_MIN;
  for (int i = 0; i < n - 1; i++) {
    x = a[i] - a[i + 1];
    ans = max(ans, x);
  }
  if (ans - c < 0)
    cout << 0 << endl;
  else
    cout << ans - c << endl;
}
