#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long Max = 1000;
const int inf = INT32_MIN;
long long dp[101][101][27];
long long path[101][27];
long long euphony(string s, long long i, long long k, long long c,
                  long long ps[], long long arr[27][27]) {
  if (i < 0) return 0;
  if (dp[i][k][c] != inf) return dp[i][k][c];
  if (k < 0) return 0;
  long long ans = 0;
  if (k >= 1) {
    for (char al = 'a'; al <= 'z'; al++) {
      string temp = s;
      long long sub = 0;
      if (temp[i] != al) {
        sub++;
        temp[i] = al;
      }
      long long ret = euphony(temp, i - 1, k - sub, al - 'a', ps, arr);
      if (i != temp.length() - 1) {
        ret += arr[al - 'a'][c];
      }
      if (ret > ans) {
        ans = ret;
        path[i][c] = al - 'a';
      }
    }
  } else {
    ans = euphony(s, i - 1, k, s[i] - 'a', ps, arr) + arr[s[i] - 'a'][c];
  }
  return dp[i][k][c] = ans;
}
int main() {
  long long arr[27][27];
  for (int i = 0; i < 27; i++) {
    for (int j = 0; j < 27; j++) {
      arr[i][j] = 0;
    }
  }
  for (long long i = 0; i <= 100; i++) {
    for (long long j = 0; j <= 100; j++)
      for (long long l = 0; l <= 26; l++) {
        dp[i][j][l] = inf;
        path[j][l] = -1;
      }
  }
  string s;
  cin >> s;
  long long k;
  cin >> k;
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    char x, y;
    cin >> x >> y;
    long long c;
    cin >> c;
    arr[x - 'a'][y - 'a'] = c;
  }
  long long ps[s.length()];
  ps[0] = 0;
  for (int i = 1; i < s.length(); i++) {
    ps[i] = ps[i - 1];
    if (arr[s[i - 1] - 'a'][s[i] - 'a'] != inf)
      ps[i] += arr[s[i - 1] - 'a'][s[i] - 'a'];
  }
  cout << euphony(s, s.length() - 1, k, 26, ps, arr) << endl;
}
