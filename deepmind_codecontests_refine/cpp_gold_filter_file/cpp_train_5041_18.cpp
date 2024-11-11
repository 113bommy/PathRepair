#include <bits/stdc++.h>
using namespace std;
long long ans[30], mx, sz, p[30], q[30];
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  for (int i = 1; i <= s.size(); i++) {
    sz = 0;
    p[s[i - 1] - 'a'] = i;
    for (int j = 0; j <= 25; j++) {
      if (p[j]) {
        q[++sz] = p[j];
      }
    }
    sort(q + 1, q + sz + 1);
    mx = max(mx, sz);
    for (int j = 1; j <= sz; j++) {
      ans[sz - j + 1] += q[j] - q[j - 1];
    }
  }
  cout << mx << "\n";
  for (int i = 1; i <= mx; i++) {
    cout << ans[i] << "\n";
  }
}
