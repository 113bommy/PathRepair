#include <bits/stdc++.h>
using namespace std;
bool isUsername(string s) {
  size_t pos = s.find('@');
  if ((pos > 16) || (pos == 0)) return false;
  for (int i = 0; i < pos; ++i) {
    if (!((s[i] >= 48 && s[i] <= 57) || (s[i] >= 65 && s[i] <= 90) ||
          (s[i] >= 97 && s[i] <= 122) || (s[i] == '_')))
      return false;
  }
  return true;
}
bool isHostname(string s) {
  size_t pos1 = s.find('@');
  size_t pos2 = s.find('/');
  char store[1001] = "A";
  if (pos2 == s.length() - 1)
    return false;
  else if (pos2 > s.length() - 1) {
    int j = 0;
    for (int i = pos1 + 1; i < s.length(); ++i) {
      store[j] = s[i];
      ++j;
    }
  } else {
    int j = 0;
    for (int i = pos1 + 1; i < pos2; ++i) {
      store[j] = s[i];
      ++j;
    }
  }
  if ((strlen(store) > 32) || (strlen(store) == 1)) return false;
  int count = 0;
  for (int i = 0; i < strlen(store); ++i) {
    if (!((store[i] >= 48 && store[i] <= 57) ||
          (store[i] >= 65 && store[i] <= 90) ||
          (store[i] >= 97 && store[i] <= 122) || (store[i] == '_') ||
          (store[i] == '.')))
      return false;
    if (store[i] != '.')
      ++count;
    else if (count == 0)
      return false;
    else
      count = 0;
  }
  if (store[strlen(store) - 1] == '.') return false;
  return true;
}
bool isResource(string s) {
  size_t pos1 = s.find('@');
  size_t pos2 = s.find('/');
  char store[1001] = "A";
  if ((pos2 == s.length() - 1))
    return false;
  else if (pos2 > s.length() - 1)
    return true;
  else {
    int j = 0;
    for (int i = pos2 + 1; i < s.length(); ++i) {
      store[j] = s[i];
      ++j;
    }
  }
  if (strlen(store) > 16) return false;
  for (int i = 0; i < strlen(store); ++i)
    if (!((store[i] >= 48 && store[i] <= 57) ||
          (store[i] >= 65 && store[i] <= 90) ||
          (store[i] >= 97 && store[i] <= 122) || (store[i] == '_')))
      return false;
  return true;
}
bool isID(string s) {
  if (isUsername(s) && isHostname(s) && isResource(s))
    return true;
  else
    return false;
}
int main() {
  string s;
  getline(cin, s);
  if (isID(s))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
