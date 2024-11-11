#include <bits/stdc++.h>
using namespace std;
int len;
string str;
bool isletter(char c) {
  if (c >= 'A' && c <= 'Z') return true;
  if (c >= 'a' && c <= 'z') return true;
  if (c >= '0' && c <= '9') return true;
  return false;
}
int main() {
  cin >> str;
  len = str.size();
  if (str.find("@") == -1) {
    cout << "NO";
    return 0;
  }
  int at = str.find("@");
  if (at == 0 || at > 16) {
    cout << "NO";
    return 0;
  }
  for (int i = 0; i < at; i++) {
    if (str[i] == '_' || isletter(str[i])) continue;
    cout << "NO";
    return 0;
  }
  int end_hostname;
  if (str.find('/') != -1) {
    end_hostname = str.find('/');
  } else {
    end_hostname = len;
  }
  string tmp = "";
  if (end_hostname - at - 1 > 32 || end_hostname - at - 1 == 0) {
    cout << "NO";
    return 0;
  }
  for (int i = at + 1; i < end_hostname; i++) {
    if (isletter(str[i]) || str[i] == '_')
      tmp += str[i];
    else if (str[i] == '.') {
      if (tmp.size() == 0 || tmp.size() > 16) {
        cout << "NO";
        return 0;
      }
      tmp = "";
    } else {
      cout << "NO";
      return 0;
    }
  }
  if (!tmp.size()) {
    cout << "NO";
    return 0;
  }
  if (len - 1 - end_hostname > 16 || len - 1 - end_hostname == 0) {
    cout << "NO";
    return 0;
  }
  for (int i = end_hostname + 1; i < len; i++) {
    if (str[i] == '_' || isletter(str[i])) continue;
    cout << "NO";
    return 0;
  }
  cout << "YES";
  return 0;
}
