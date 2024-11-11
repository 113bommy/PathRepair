#include <bits/stdc++.h>
using namespace std;
void read(vector<int>& arr) {
  for (int i = 0; i < arr.size(); i++) cin >> arr[i];
}
int pow_mod(int a, int power, int mod) {
  long long res = 1;
  while (power > 1) {
    if (power % 2) res = ((res % mod) * (a % mod)) % mod;
    power /= 2;
    a = (a * 1LL * a) % mod;
  }
  return (res * a) % mod;
}
long long pow_(long long a, long long power) {
  long long res = 1;
  while (power > 1) {
    if (power % 2) res = res * a;
    power /= 2;
    a = a * a;
  }
  return res * a;
}
int mod_inv(int a, int mod) { return pow_mod(a, mod - 2, mod); }
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  vector<int> ans(n, 0);
  read(arr);
  int chng = 0, curr = 1, max_ = 1;
  for (int i = 1; i < n; i++) {
    if (arr[i] != arr[i - 1]) {
      curr = 0;
      chng++;
    }
    curr++;
    max_ = max(max_, curr);
  }
  int grp = chng + 1;
  if (grp % 2) {
    if (arr[0] == arr[n - 1]) {
      int curr = 1, cng = 0;
      ans[0] = 1;
      for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
          cng = 1;
          curr = curr == 1 ? 2 : 1;
        }
        ans[i] = curr;
      }
      cout << 1 + cng << endl;
      for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
      }
    } else if (chng) {
      if (max_ > 1) {
        bool done = 0;
        int curr = 1;
        cout << 2 << endl << 1 << " ";
        for (int i = 1; i < n; i++) {
          if (arr[i] == arr[i - 1]) {
            if (!done) {
              curr = (curr == 1) ? 2 : 1;
              done = 1;
            }
          } else {
            curr = (curr == 1) ? 2 : 1;
          }
          cout << curr << " ";
        }
      } else {
        cout << 3 << endl;
        ans[n - 1] = 3;
        for (int i = n - 1; i >= 0 && arr[i] == arr[n - 1]; i--) {
          ans[i] = 3;
        }
        int curr = 1;
        ans[0] = 1;
        for (int i = 0; i < n && ans[i] != 3; i++) {
          if (arr[i] != arr[i - 1]) curr = curr == 1 ? 2 : 1;
          ans[i] = curr;
        }
        for (int i : ans) cout << i << " ";
      }
    } else {
      cout << 1 << endl;
      for (int i = 0; i < n; i++) cout << 1 << " ";
    }
  } else {
    int c = 1;
    cout << 2 << endl << 1 << " ";
    for (int i = 1; i < n; i++) {
      if (arr[i] != arr[i - 1]) c = c == 1 ? 2 : 1;
      cout << c << " ";
    }
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
