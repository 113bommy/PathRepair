#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  if (s.length() < 26) {
    cout << -1;
    return 0;
  }
  int hash[26] = {0}, que = 0;
  for (int i = 0; i < 26; i++) {
    if (s[i] == '?')
      que++;
    else
      hash[s[i] - 'A']++;
  }
  int flag = 1, i;
  for (i = 0; i < 26; i++) {
    if (hash[i] > 1) flag = 0;
  }
  if (flag == 1) {
    for (int j = 0; j < 26; j++) {
      if (s[j] == '?') {
        for (int k = 0; k < 26; k++) {
          if (hash[k] == 0) {
            hash[k] = 1;
            s[j] = k + 'A';
            break;
          }
        }
      }
    }
    for (int j = 26; j < s.length(); j++) {
      if (s[j] == '?') s[j] = 'A';
    }
  } else {
    for (i = 26; i < s.length(); i++) {
      flag = 1;
      if (s[i - 26] == '?')
        que--;
      else
        hash[s[i - 26] - 'A']--;
      if (s[i] == '?')
        que++;
      else
        hash[s[i] - 'A']++;
      for (int j = 0; j < 26; j++) {
        if (hash[j] > 1) flag = 0;
      }
      if (flag == 1) {
        for (int j = i - 25; j <= i; j++) {
          if (s[j] == '?') {
            for (int k = 0; k < 26; k++) {
              if (hash[k] == 0) {
                hash[k] = 1;
                s[j] = k + 'A';
                break;
              }
            }
          }
        }
        for (int j = 26; j < s.length(); j++) {
          if (s[j] == '?') s[j] = 'A';
        }
        break;
      }
    }
  }
  if (flag == 1)
    cout << s;
  else
    cout << -1;
  return 0;
}
