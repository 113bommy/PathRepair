#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10, maxm = (1 << 17), mod = 1e9 + 7, hash = 701;
const double PI = 3.14159265359, E = 2.71828;
long long d[150][3010];
void pre() {
  for (int i = 0; i < 3000; i++) d[0][i] = 1;
  for (int i = 1; i < 3000; i++)
    for (int j = 1; j < 120; j++)
      d[j][i] = (d[j][i - 1] + d[j - 1][i - 1]) % mod;
}
int main() {
  ios::sync_with_stdio(0);
  long long n, ans, sum, k;
  string s;
  cin >> n;
  pre();
  while (n--) {
    ans = sum = 0;
    cin >> s, k = s.size() - 1;
    for (int i = 0; i <= k; i++) sum += s[i] - 'a';
    ans = d[k][sum + k];
    for (int i = 1; i <= k; i++) {
      sum -= 26;
      if (sum < 0) break;
      ans = (ans + (i % 2 ? -1 : 1) * ((d[i][k + 1] * d[k][sum + k]) % mod) +
             mod) %
            mod;
    }
    cout << (ans + mod - 1) % mod << endl;
  }
  return 0;
}
