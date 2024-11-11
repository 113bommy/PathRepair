#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long int mod = 1000000007;
const long long int N = 200001;
const long long int M = 1;
struct point {
  long long int x, y;
};
long long int fast_exp(long long int x, long long int n) {
  if (n == 0) return 1;
  long long int ans = 1;
  if (n % 2 == 0) {
    ans = fast_exp(x, n / 2);
    ans = ans * ans % mod;
  } else
    ans = fast_exp(x, n - 1) * x % mod;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int _ = 1;
  int test = 0;
  while (_--) {
    test++;
    long long int n, m, x = 0, y, ans = 0, k;
    cin >> n;
    string s;
    while (cin >> s) {
      x = 0;
      for (auto i : s) {
        if (s[i] >= 'A' && s[i] <= 'Z') x++;
      }
      ans = max(x, ans);
    }
    cout << ans << "\n";
  }
  return 0;
}
