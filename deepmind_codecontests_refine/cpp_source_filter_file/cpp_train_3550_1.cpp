#include <bits/stdc++.h>
using namespace std;
const bool testcase = 0;
const long long int mod1 = 1000000007;
const long long int mod2 = 998244353;
void solve(long long int& kes) {
  long long int n, m;
  cin >> n;
  std::vector<long long int> a(n);
  for (auto& it : a) {
    cin >> it;
  }
  cin >> m;
  std::vector<long long int> b(m);
  for (auto& it : b) {
    cin >> it;
  }
  long long int i = 0, j = 0, ans = 0;
  while (i < n && j < m) {
    if (a[i] != b[j]) {
      long long int sumA = a[i], sumB = b[j];
      i++;
      j++;
      while (i < n && j < m && sumA != sumB) {
        if (sumA > sumB) {
          sumB += b[j];
          j++;
        } else {
          sumA += a[i];
          i++;
        }
      }
      if (sumA != sumB) {
        while (i < n) {
          sumA += a[i];
          i++;
        }
        while (j < m) {
          sumB += b[j];
          j++;
        }
        if (sumA != sumB) {
          cout << -1 << '\n';
          return;
        } else {
          ans++;
        }
      } else {
        ans++;
      }
    } else {
      ans++;
      i++;
      j++;
    }
  }
  if (i != n && j != m) {
    cout << -1 << '\n';
    return;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long int t = 1;
  int T_T = 1;
  if (testcase) {
    cin >> T_T;
  }
  while (T_T--) {
    solve(t);
    t++;
  }
  return 0;
}
