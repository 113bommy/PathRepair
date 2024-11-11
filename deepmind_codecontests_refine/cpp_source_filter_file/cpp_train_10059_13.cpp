#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
long long a[N];
long long b[N];
long long ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  long long n = s.size();
  for (int i = 1; i <= s.size(); i++) {
    a[i] = a[i - 1];
    b[i] = b[i - 1];
    if (s[i - 1] == 'a') {
      a[i]++;
    } else {
      b[i]++;
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = n; j > i; j--) {
      ans = max(ans, n - b[i] - (b[n] - b[j]) - (a[j] - a[i]));
    }
  }
  cout << ans;
  return 0;
}
