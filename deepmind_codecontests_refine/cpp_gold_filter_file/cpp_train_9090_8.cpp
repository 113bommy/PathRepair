#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string s;
  long long h[n + 1];
  long long m[n + 1];
  char first[n + 1];
  for (int i = 0; i <= n; i++) {
    getline(cin, s);
    if (s[1] == '1' and s[2] == '2')
      h[i] = 0;
    else
      h[i] = (s[1] - '0') * 10 + (s[2] - '0');
    m[i] = (s[4] - '0') * 10 + (s[5] - '0') + h[i] * 60;
    first[i] = s[7];
  }
  long long ans = 1;
  long long cnt = 1;
  for (int i = 2; i <= n; i++) {
    if (m[i] == m[i - 1] and first[i] == first[i - 1]) {
      cnt++;
      if (cnt > 10) ans++, cnt = 1;
    } else {
      cnt = 1;
      if (first[i] < first[i - 1])
        ans++;
      else if (first[i] == first[i - 1] and m[i] < m[i - 1])
        ans++;
    }
  }
  cout << ans << "\n";
}
