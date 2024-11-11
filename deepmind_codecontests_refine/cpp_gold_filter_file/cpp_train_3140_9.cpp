#include <bits/stdc++.h>
using namespace std;
const int inf = 2147483647;
long long read() {
  long long first = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    first = first * 10 + ch - '0';
    ch = getchar();
  }
  return first * f;
}
void print(long long first) {
  if (first < 0) putchar('-'), first = -first;
  short a[20] = {}, sz = 0;
  while (first > 0) a[sz++] = first % 10, first /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
int dp[3333];
string s;
const int mod = 1000003;
int m;
int main() {
  cin >> s;
  dp[0] = 1;
  for (int i = 0; i < s.size(); i++) {
    if (!isdigit(s[i])) {
      if ((i == 0 || !isdigit(s[i - 1])) && (s[i] == '*' || s[i] == '/')) {
        cout << 0 << endl;
        return 0;
      }
      m++;
      for (int j = m; j > 0; j--) {
        dp[j] = dp[j - 1];
      }
      dp[0] = 0;
    } else if (i != 0 && !isdigit(s[i - 1])) {
      for (int j = m; j > 0; j--) {
        dp[j - 1] = (dp[j - 1] + dp[j]) % mod;
      }
    }
  }
  print(dp[0]);
  return 0;
}
