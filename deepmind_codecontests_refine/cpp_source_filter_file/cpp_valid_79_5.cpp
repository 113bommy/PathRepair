#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma,sse2")
#pragma GCC optimization("unroll-loops")
using namespace std;
int64_t t, n, l, r, a[1000005];
string s;
bool prime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}
void solve() {
  int vt = -1;
  for (int i = 0; i < n; i++) {
    if (int(s[i]) % 2 == 0 && s[i] != '2') vt = int(s[i]) - 48;
  }
  if (vt > -1)
    cout << 1 << "\n" << vt << "\n";
  else {
    for (int i = 0; i < n; i++) {
      if (s[i] == '9') vt = 9;
      if (s[i] == '1') vt = 1;
    }
    if (vt > 0)
      cout << 1 << "\n" << 9 << "\n";
    else {
      if (n <= 5) {
        bool b[6];
        int ans = 99999;
        for (int i = 1; i <= n; i++) b[i] = 0;
        b[n] = 1;
        while (1) {
          int sum = 0, num = 1;
          vector<int> v;
          for (int i = n; i >= 1; i--) {
            if (b[i]) v.push_back(int(s[i - 1]) - 48);
          }
          for (auto i : v) {
            sum += i * num;
            num *= 10;
          }
          if (!prime(sum)) ans = min(ans, sum);
          bool f = 0;
          for (int i = n; i >= 1; i--) {
            if (!b[i]) {
              f = 1;
              b[i] = 1;
              for (int j = i + 1; j <= n; j++) b[j] = 0;
              break;
            }
          }
          if (!f) break;
        }
        if (10 <= ans && ans <= 99)
          cout << 2 << "\n" << ans << "\n";
        else if (100 <= ans && ans <= 999)
          cout << 3 << "\n" << ans << "\n";
        else if (1000 <= ans && ans <= 9999)
          cout << 4 << "\n" << ans << "\n";
        else
          cout << 5 << "\n" << ans << "\n";
      } else {
        int ans = 999;
        for (int i = 0; i < s.size() - 1; i++) {
          for (int j = i + 1; j < s.size(); j++) {
            int num = (int(s[i]) - 48) * 10 + int(s[j]) - 48;
            if (!prime(num)) ans = min(ans, num);
          }
        }
        for (int i = 0; i < s.size() - 2; i++) {
          for (int j = i + 1; j < s.size() - 1; j++) {
            for (int k = j + 1; k < s.size(); k++) {
              int num = (int(s[i]) - 48) * 100 + (int(s[j]) - 48) * 10 +
                        int(s[k]) - 48;
              if (!prime(num)) ans = min(ans, num);
            }
          }
        }
        if (10 <= ans && ans <= 99)
          cout << 2 << "\n" << ans << "\n";
        else
          cout << 3 << "\n" << ans << "\n";
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> t;
  while (t--) {
    cin >> n >> s;
    solve();
  }
}
