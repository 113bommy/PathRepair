#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  int sum1 = 0, sum2;
  int len = str.length();
  int temp = len;
  for (int i = 0; i < len; i++) {
    if (str[i] == '7') sum1 = sum1 + pow(2, temp);
    temp--;
  }
  sum1++;
  sum2 = 2 * (pow(2, len - 1) - 1);
  cout << sum1 + sum2 << endl;
  return 0;
}
