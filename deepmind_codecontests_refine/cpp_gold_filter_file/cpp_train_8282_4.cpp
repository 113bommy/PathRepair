#include <bits/stdc++.h>
using namespace std;
int find_sym(string s) {
  int ans = 999999;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '#' || s[i] == '*' || s[i] == '&') {
      ans = i;
      break;
    }
  }
  int j = 1;
  for (int i = s.size() - 1; i >= 0; i--, j++) {
    if (s[i] == '#' || s[i] == '*' || s[i] == '&') {
      ans = min(ans, j);
      break;
    }
  }
  return ans;
}
int find_dig(string s) {
  int ans = 999999;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      ans = i;
      break;
    }
  }
  int j = 1;
  for (int i = s.size() - 1; i >= 0; i--, j++) {
    if (s[i] >= '0' && s[i] <= '9') {
      ans = min(ans, j);
      break;
    }
  }
  return ans;
}
int find_ch(string s) {
  int ans = 999999;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      ans = i;
      break;
    }
  }
  int j = 1;
  for (int i = s.size() - 1; i >= 0; i--, j++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      ans = min(ans, j);
      break;
    }
  }
  return ans;
}
int main() {
  int n, m;
  cin >> n >> m;
  int dig[100];
  int ch[100];
  int symbol[100];
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    symbol[i] = find_sym(s);
    dig[i] = find_dig(s);
    ch[i] = find_ch(s);
  }
  int ans = 999999;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (j != i)
        for (int k = 0; k < n; k++)
          if (k != i && k != j) ans = min(ans, dig[i] + symbol[j] + ch[k]);
  cout << ans;
}
