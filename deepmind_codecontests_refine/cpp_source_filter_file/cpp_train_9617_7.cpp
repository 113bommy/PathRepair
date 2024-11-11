#include <bits/stdc++.h>
using namespace std;
int n;
double ans = 0;
int arr[100010] = {0};
int lazy[100010] = {0};
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  int sz = 1;
  arr[0] = 0;
  for (long long int i = (1); i <= (n); i++) {
    int a, t, x, k;
    cin >> t;
    if (t == 1) {
      cin >> a >> x;
      ans += a * (x * 1.0 / sz);
      lazy[a - 1] += x;
      arr[a - 1] += x;
    } else if (t == 2) {
      cin >> k;
      arr[sz] = k;
      ans = (sz * ans + k) / (sz + 1);
      ++sz;
    } else {
      lazy[sz - 2] += lazy[sz - 1];
      arr[sz - 2] += lazy[sz - 1];
      lazy[sz - 1] = 0;
      ans = (ans * sz - arr[sz - 1]) / (sz - 1);
      --sz;
    }
    cout << setprecision(6) << fixed;
    cout << ans << endl;
  }
  return 0;
}
