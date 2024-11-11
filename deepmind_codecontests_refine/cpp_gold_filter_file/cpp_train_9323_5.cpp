#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long dp[200005][11];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, a, b, k;
  cin >> n >> a >> b >> k;
  string s;
  cin >> s;
  long long c = 0;
  vector<long long> v;
  for (long long i = 1; i <= n; i++) {
    if (s[i - 1] == '1') {
      c = 0;
    } else {
      c++;
      if (c == b) {
        v.push_back(i);
        c = 0;
      }
    }
  }
  cout << v.size() - a + 1 << "\n";
  for (long long i = 0; i < v.size() - a + 1; i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
  return 0;
}
