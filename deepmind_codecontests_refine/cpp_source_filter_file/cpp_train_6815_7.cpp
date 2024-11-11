#include <bits/stdc++.h>
using namespace std;
long long int a[1000010];
long long int b[1000010];
long long int dp[12][1000005];
int main() {
  string str;
  long long int num1, num2, i, j;
  cin >> str;
  cin >> num1 >> num2;
  if (str[0] == '0') {
    cout << "NO\n";
    return 0;
  }
  long long int rm = 0;
  for (i = 0; i < str.size(); ++i) {
    rm = rm * 10;
    rm = rm + (str[i] - '0');
    rm = rm % num1;
    if (rm == 0) {
      a[i] = 1;
    }
  }
  for (i = 0; i <= 9; ++i) {
    rm = i;
    rm = rm % num2;
    dp[i][0] = rm;
    for (j = 1; j <= str.size() - 1; ++j) {
      rm = rm * 10;
      rm = rm % num2;
      dp[i][j] = rm;
    }
  }
  rm = 0;
  for (i = str.size() - 1; i >= 0; --i) {
    rm = rm + dp[str[i] - '0'][str.size() - 1 - i];
    rm = rm % num2;
    if (rm == 0) {
      b[i] = 1;
    }
  }
  for (i = 0; i < str.size() - 1; ++i) {
    if (str[i + 1] - '0' && a[i] == 1 && b[i + 1] == 1) break;
  }
  if (i != str.size() - 1) {
    cout << "YES\n";
    for (j = 0; j < i + 1; ++j) {
      cout << str[j];
    }
    cout << "\n";
    for (j = i + 1; j <= str.size(); ++j) {
      cout << str[j];
    }
  } else {
    cout << "NO\n";
  }
  return 0;
}
