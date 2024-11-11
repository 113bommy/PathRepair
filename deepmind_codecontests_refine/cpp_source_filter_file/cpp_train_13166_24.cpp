#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
map<long long, long long> m[26];
int c[26], sum[N];
string s;
int main() {
  for (int i = 0; i < 26; ++i) cin >> c[i];
  cin >> s;
  sum[0] = 0;
  long long ans = 0;
  int n = s.length();
  for (int i = 1; i <= n; ++i) {
    int k = s[i - 1] - 'a';
    sum[i] = sum[i - 1] + c[k];
    ans += m[k][sum[i - 1]];
    m[k][sum[i]]++;
  }
  cout << ans << "\n";
}
