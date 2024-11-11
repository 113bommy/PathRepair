#include <bits/stdc++.h>
using namespace std;
bool is_polyndrome(string str) {
  for (int i = 0; i < str.size() / 2; i++)
    if (str[i] != str[str.size() - 1 - i]) return false;
  return true;
}
int main() {
  string str;
  cin >> str;
  int times = 0;
  char max_char = 'a';
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == max_char)
      times++;
    else if (str[i] > max_char) {
      max_char = str[i];
      times++;
    }
  }
  cout << string(times, max_char) << endl;
  return 0;
}
