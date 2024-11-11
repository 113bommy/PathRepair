#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t) {
    t--;
    long long n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (k == 1)
      cout << s;
    else {
      if (s[k - 1] != s[0] || k == n)
        cout << s[k - 1];
      else if (s[k] == s[n - 1]) {
        for (long long i = 0; i < n; i += k) cout << s[i];
      } else
        cout << s.substr(k - 1);
    }
    cout << '\n';
  }
}
