#include <bits/stdc++.h>
using namespace std;
int main() {
  string ch, ch1 = "";
  cin >> ch;
  for (int i = 0; i < ch.length(); i++) {
    if (ch1.find(ch[i]) != std::string::npos) ch1 = ch1 + ch[i];
  }
  if (ch1.length() % 2 == 0)
    cout << "CHAT WITH HER!";
  else
    cout << "IGNORE HIM!";
  return 0;
}
