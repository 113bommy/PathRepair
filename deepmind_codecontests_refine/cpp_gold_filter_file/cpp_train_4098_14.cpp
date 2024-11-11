#include <bits/stdc++.h>
using namespace std;
const int INF = 20050226;
string user, host, resou;
int n1, n2, a, b;
bool check(char x) {
  return x >= 'a' and x <= 'z' or x >= 'A' and x <= 'Z' or x == '_' or
         x <= '9' and x >= '0';
}
int main() {
  string s;
  cin >> s;
  int len = s.size();
  for (int i = 0; i < len; i++) {
    if (s[i] == '@') {
      n1++;
    }
    if (s[i] == '/') {
      n2++;
    }
  }
  if (n1 != 1 or n2 != 1 and n2 != 0) {
    cout << "NO";
    return 0;
  }
  a = s.find_first_of('@');
  user = s.substr(0, a);
  if (n2 != 0) {
    b = s.find_first_of('/');
    host = s.substr(a + 1, b - a - 1);
    resou = s.substr(b, len - b);
  } else if (n2 == 0) {
    host = s.substr(a + 1, len);
  }
  for (int i = 0; i < user.size(); i++) {
    if (!check(user[i])) {
      cout << "NO";
      return 0;
    }
  }
  bool dot = false;
  int cnt = 0;
  for (int i = 0; i < host.size(); i++) {
    if (!check(host[i]) and host[i] != '.') {
      cout << "NO";
      return 0;
    }
    if (host[i] == '.') {
      if (cnt > 16 or cnt == 0) {
        cout << "NO";
        return 0;
      }
      cnt = -1;
    }
    cnt++;
  }
  if (host[host.size() - 1] == '.') {
    cout << "NO";
    return 0;
  }
  for (int i = 1; i < resou.size(); i++) {
    if (!check(resou[i])) {
      cout << "NO";
      return 0;
    }
  }
  if (user.size() > 16 or user.size() == 0) {
    cout << "NO";
    return 0;
  }
  if (host.size() > 32 or host.size() == 0) {
    cout << "NO";
    return 0;
  }
  if (resou.size() > 17) {
    cout << "NO";
    return 0;
  }
  if (s[s.size() - 1] == '/') {
    cout << "NO";
    return 0;
  }
  cout << "YES" << endl;
  return 0;
}
