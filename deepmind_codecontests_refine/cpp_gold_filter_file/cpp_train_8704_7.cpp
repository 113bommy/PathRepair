#include <bits/stdc++.h>
bool palindrome(std::string w) {
  int len = w.length();
  for (int i = 0; i < len / 2; i++)
    if (w[i] != w[len - i - 1]) return false;
  return true;
}
int main() {
  std::string x, y = "";
  std::cin >> x;
  for (int i = x.length() - 1; i >= 0; i--)
    if (x[i] == '0')
      y += "0";
    else
      break;
  x = y + x;
  std::cout << (palindrome(x) ? "YES" : "NO") << std::endl;
  return 0;
}
