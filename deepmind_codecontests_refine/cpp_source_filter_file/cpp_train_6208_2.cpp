#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << "\n";
  err(++it, args...);
}
long long inf = 1e18;
long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long i, j, k, x, y, c, var, n, m, z, ind1, ind2,
      ans = 0, flag = 0, limit1 = 0, limit2 = 0, limit3 = 0;
  long long arr[6];
  for (i = 0; i < 6; i++) {
    cin >> arr[i];
  }
  for (i = 0; i < 6; i++) {
    ans += arr[i];
  }
  if (ans % 2) {
    cout << "NO";
    return 0;
  }
  for (i = 0; i < 6; i++) {
    for (j = i + 1; j < 6; j++) {
      for (k = j + 1; k < n; k++) {
        if (arr[i] + arr[j] + arr[k] == ans / 2) {
          cout << "YES";
          return 0;
        }
      }
    }
  }
  cout << "NO";
  return 0;
}
