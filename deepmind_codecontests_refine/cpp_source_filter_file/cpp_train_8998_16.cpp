#include <bits/stdc++.h>
using namespace std;
int pow_2[] = {1, 2, 4, 3};
int pow_3[] = {1, 3, 4, 2};
int pow_4[] = {1, 4, 1, 4};
int main() {
  string str;
  cin >> str;
  str = "0" + str;
  int len = str.length();
  int i = ((str[len - 2] - '0') * 10 + (str[len - 1] - '0'));
  int res = (1 + pow_2[i] + pow_3[i] + pow_4[i]) % 5;
  cout << res;
  return 0;
}
