#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
const int mod = 1e9 + 7;
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0)
    if (b & 1) {
      res = (long long)(res * 1ll * a);
      --b;
    } else {
      a = (long long)(a * 1ll * a);
      b >>= 1;
    }
  return (long long)res;
}
vector<vector<int>> pref;
bool check(int ind_l, int ind_r) {
  if (ind_l == 0) {
    if (pref[0][ind_r] != 0)
      return false;
    else
      return true;
  } else if (pref[0][ind_r] - pref[0][ind_l - 1] != 0)
    return false;
  else
    return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ind_x = -1, ind_y = -1;
    int ans;
    for (int i = 0; i < n; i++) {
      if (s[i] == '>') {
        ans = i;
        break;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '<') {
        ans = min(n - i - 1, ans);
        break;
      }
    }
    if (ans == 1e9) ans = 0;
    cout << ans << endl;
  }
  return 0;
}
