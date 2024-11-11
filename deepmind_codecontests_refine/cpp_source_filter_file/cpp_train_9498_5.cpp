#include <bits/stdc++.h>
using namespace std;
string text, str, res;
int _prev = 0;
string DecToBin(int number) {
  if (number == 0) return "0";
  if (number == 1) return "1";
  if (number % 2 == 0)
    return DecToBin(number / 2) + "0";
  else
    return DecToBin(number / 2) + "1";
}
int BinToDec(string number) {
  int result = 0, pow = 1;
  for (int i = number.length() - 1; i >= 0; --i, pow <<= 1)
    result += (number[i] - '0') * pow;
  return result;
}
int main() {
  getline(cin, text);
  for (int i = 0; i < text.length(); i++) {
    str.clear();
    str = DecToBin((int)text[i]);
    reverse(str.begin(), str.end());
    if (str.length() < 8) str.append("0");
    printf("%d\n", abs(_prev - BinToDec(str) + 256) % 256);
    _prev = BinToDec(str);
  }
  return 0;
}
