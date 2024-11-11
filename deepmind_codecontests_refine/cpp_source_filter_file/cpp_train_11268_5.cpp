#include <bits/stdc++.h>
using namespace std;
int MAX = 1e5 + 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int test = 1;
  cin >> test;
  while (test--) {
    long long int n, ans = 1;
    cin >> n;
    vector<long long int> a(n, 0);
    for (long long int &i : a) cin >> i;
    long long int diff = 0, mx = a[0];
    for (long long int i = 0LL; i < n; ++i) {
      diff = max(diff, mx - a[i]);
      mx = max(mx, a[i]);
    }
    while (diff > 0) {
      diff -= pow(2, ans - 1);
      ans++;
    }
    cout << 1 + ans << endl;
  }
  return 0;
}
