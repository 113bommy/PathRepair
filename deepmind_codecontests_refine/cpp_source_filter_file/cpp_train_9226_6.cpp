#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 5;
const long long MOD = 1e9 + 7;
const long long PHI = 1e9 + 6;
const long double eps = 1e-9;
const long double pi = atan(1) * 4;
void fileio() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
int t, n;
int sm = 3, lg = 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n;
    if (n % 3 == 0 || n % 7 == 0)
      cout << "Yes";
    else {
      bool flag = false;
      for (int i = 1; i <= 34; i++)
        if ((n - 3 * i) % 7 == 0) {
          flag = true;
          break;
        } else if (n - 3 * i <= 0)
          break;
      if (flag)
        cout << "Yes";
      else
        cout << "No";
    }
    cout << '\n';
  }
  return 0;
}
