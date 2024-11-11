#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e6 + 5, inf = 1e18, mod = 1e9 + 7;
long long int freq[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  long long int n = ((long long int)((s).size()));
  long long int c = 0;
  long long int ans = 1;
  long long int flag = 0;
  for (long long int i = n - 1; i >= 0; i--) {
    if (s[i] == '0') {
      c++;
    } else {
      if (flag == 0) {
        ans = c + 1;
        c = 0;
        flag = 1;
      } else {
        long long int cur = (ans * (c + 1)) % mod;
        long long int pre = ans;
        for (long long int i = 0; i < c + 1; ++i) {
          pre -= freq[i];
          pre += mod;
          pre %= mod;
          freq[i] = ans;
        }
        c = 0;
        ans = cur + pre;
        ans %= mod;
      }
    }
  }
  ans = (ans * min(n, (c + 1))) % mod;
  cout << ans << "\n";
  return 0;
}
