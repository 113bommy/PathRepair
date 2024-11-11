#include <bits/stdc++.h>
using namespace std;
long long pow(long long num) {
  long long res = 1;
  for (int i = 1; i <= num; i++) {
    res *= 2;
    res % 1000003;
  }
  return res % 1000003;
}
void conc(string str, string &res) {
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '>') {
      res += "1000";
    } else if (str[i] == '<') {
      res += "1001";
    } else if (str[i] == '+') {
      res += "1010";
    } else if (str[i] == '-') {
      res += "1011";
    } else if (str[i] == '.') {
      res += "1100";
    } else if (str[i] == ',') {
      res += "1101";
    } else if (str[i] == '[') {
      res += "1110";
    } else if (str[i] == ']') {
      res += "1111";
    }
  }
}
int main() {
  string str;
  string res;
  cin >> str;
  long long sum = 0;
  conc(str, res);
  for (int i = (res.length()) - 1, y = 0; i >= 0; i--, y++) {
    if (res[i] == '1') {
      sum += pow(y);
      sum % 1000003;
    }
  }
  cout << sum % 1000003 << endl;
  return 0;
}
