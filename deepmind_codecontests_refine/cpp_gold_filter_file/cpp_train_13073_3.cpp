#include <bits/stdc++.h>
using namespace std;
int hole[1000005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int q = 1;
  while (q--) {
    int n;
    cin >> n;
    string s, m;
    cin >> s >> m;
    sort(s.begin(), s.end());
    sort(m.begin(), m.end());
    int ans = n - 1;
    for (int i = n - 1; i >= 0; i--)
      if (s[i] <= m[ans]) ans--;
    cout << ans + 1 << "\n";
    ans = 0;
    for (long long int i = 0; i < n; i++) {
      if (m[i] > s[ans]) ans++;
    }
    cout << ans << "\n";
  }
}
