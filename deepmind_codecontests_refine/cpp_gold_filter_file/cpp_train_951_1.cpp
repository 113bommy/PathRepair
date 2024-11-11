#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18 + 1LL;
const long long mod = 1e9 + 7LL;
void solve();
void ITO();
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ITO();
  long long t = 1;
  while (t--) solve();
  return 0;
}
const long long N = (1e6 + 5);
void solve() {
  long long n;
  cin >> n;
  long long arr[n];
  for (auto &x : arr) cin >> x;
  string res;
  long long last = 0, i = 0, j = n - 1;
  while (i <= j) {
    if (arr[i] > last and arr[j] > last) {
      if (arr[i] < arr[j])
        res += 'L', last = arr[i++];
      else if (arr[j] < arr[i])
        res += 'R', last = arr[j--];
      else {
        string frwd = "L", bkwd = "R";
        for (long long k = i + 1; k <= j; k++) {
          if (arr[k] > arr[k - 1])
            frwd += "L";
          else
            break;
        }
        for (long long k = j - 1; k >= i; k--) {
          if (arr[k] > arr[k + 1])
            bkwd += "R";
          else
            break;
        }
        if (frwd.size() > bkwd.size())
          res += frwd;
        else
          res += bkwd;
        break;
      }
    } else if (arr[i] > last)
      res += 'L', last = arr[i++];
    else if (arr[j] > last)
      res += 'R', last = arr[j--];
    else
      break;
  }
  cout << res.size() << "\n" << res;
  cout << "\n";
  return;
}
void ITO() {}
