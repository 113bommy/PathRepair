#include <bits/stdc++.h>
using namespace std;
const int d[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string ans[1000010];
int a[40000000], b[1000000];
int main() {
  string str;
  int ma = 0, tot = 0, t = 0, an = 0;
  cin.tie(0);
  cin >> str;
  for (int i = 2; i < str.length() - 6; ++i)
    if (str[i] == '-' && str[i + 3] == '-' && str[i - 1] != '-' &&
        str[i + 1] != '-' && str[i + 7] != '-' && str[i + 2] != '-' &&
        str[i - 2] != '-') {
      tot++;
      for (int j = i - 2; j <= i + 7; ++j) ans[tot] += str[j];
    }
  for (int i = 1; i <= tot; ++i) {
    int sum1, sum2, sum3;
    sum1 = (ans[i][0] - '0') * 10 + (ans[i][1] - '0');
    sum2 = (ans[i][3] - '0') * 10 + (ans[i][4] - '0');
    sum3 = (ans[i][6] - '0') * 1000 + (ans[i][7] - '0') * 100 +
           (ans[i][8] - '0') * 10 + (ans[i][9] - '0');
    if (sum1 > d[sum2]) continue;
    if (sum3 < 2013 || sum3 > 2015) continue;
    if (sum1 <= 0) continue;
    a[sum3 * 10000 + sum2 * 100 + sum1]++;
    b[++t] = sum3 * 10000 + sum2 * 100 + sum1;
  }
  for (int i = 1; i <= t; ++i) {
    if (a[b[i]] > ma) ma = a[b[i]], an = b[i];
  }
  if (an % 100 < 10)
    cout << 0 << an % 100 << '-';
  else
    cout << an % 100 << '-';
  if (an / 100 % 100 < 10)
    cout << 0 << an / 100 % 100 << '-';
  else
    cout << an / 100 % 100 << '-';
  cout << an / 10000;
}
