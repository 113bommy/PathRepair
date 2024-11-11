#include <bits/stdc++.h>
using namespace std;
int dp[2000010];
string s, t;
int main() {
  int n;
  cin >> n >> t >> s;
  n--;
  for (int i = 0; i < n; i++)
    if (t[i] == 'E')
      t[i] = 'W';
    else if (t[i] == 'W')
      t[i] = 'E';
    else if (t[i] == 'N')
      t[i] = 'S';
    else
      t[i] = 'N';
  reverse(t.begin(), t.end());
  s = t + " " + s;
  n = n * 2 + 1;
  dp[0] = -1;
  for (int i = 1; i < n; i++) {
    int j = dp[i - 1];
    while (j != -1 && s[j + 1] != s[i]) j = dp[j];
    if (s[j + 1] == s[i]) j++;
    dp[i] = j;
  }
  puts(dp[n - 1] == -1 ? "YES" : "NO");
}
