#include <bits/stdc++.h>
using lli = long long int;
using li = long int;
using namespace std;
const lli MOD{998244353};
const lli INF{(false ? (INT_MAX - 1) / 2 : (lli)1e18 + 5)};
const lli N{1000001};
int main() {
  cout << setprecision(15);
  cin.tie(nullptr)->sync_with_stdio(false);
  li T{1};
  cin >> T;
  while (T--) {
    lli n{}, m{};
    cin >> n >> m;
    vector<string> arr(n);
    for (auto &i : arr) cin >> i;
    sort((arr).begin(), (arr).end());
    for (lli i{}; i < n; ++i) {
      if (arr[i] == arr[i - 1]) {
        arr.erase(arr.begin() + i);
        n--;
        i--;
      }
    }
    if (n == 1) {
      cout << arr[0] << '\n';
      continue;
    }
    string ans;
    for (lli i{}; i < m; ++i) ans += '#';
    int flag{1};
    for (lli i{}; i < m; ++i) {
      string tmp{arr[0]};
      for (lli j{}; j < 26; ++j) {
        tmp[i] = (char)(j + 'a');
        int no{};
        for (lli k{}; k < n; ++k) {
          lli cnt{};
          for (lli l{}; l < m; ++l)
            if (arr[k][l] != tmp[l]) cnt++;
          if (cnt > 1) no++;
        }
        if (!no) ans = tmp, flag = 0;
      }
    }
    if (flag) {
      cout << -1 << '\n';
      continue;
    }
    cout << ans << '\n';
  }
  return 0;
}
