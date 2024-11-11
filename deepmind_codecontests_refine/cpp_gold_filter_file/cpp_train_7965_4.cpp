#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  long long int ara[n];
  string s;
  for (long long int i = 0; i < n; i++) cin >> ara[i];
  cin >> s;
  long long int mx1 = 0, mx2 = 0, tmp;
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    if (s[i] == 'B') ans += ara[i];
  }
  tmp = ans;
  for (long long int i = 0; i < n; i++) {
    if (s[i] == 'A')
      tmp += ara[i];
    else
      tmp -= ara[i];
    mx1 = max(mx1, tmp);
  }
  tmp = ans;
  for (long long int i = n - 1; i >= 0; i--) {
    if (s[i] == 'A')
      tmp += ara[i];
    else
      tmp -= ara[i];
    mx2 = max(mx2, tmp);
  }
  cout << max(max(mx1, mx2), ans) << endl;
}
