#include <bits/stdc++.h>
using namespace std;
string s[100000];
int a[100001], cnt;
int main() {
  int n;
  char ss[100];
  cin >> n;
  gets(ss);
  for (int i = 0; i < n; i++) {
    char t[100];
    int l = 0, r = 0;
    gets(t);
    for (int j = 0; j < (int)strlen(t); j++) {
      if (t[j] == '"' && l == 0)
        l = 1;
      else if (t[j] == '"')
        r = 1;
      if (t[j] != ' ' || (l && !r)) s[i] += t[j];
    }
  }
  string block = "";
  int x = -1;
  for (int i = 0; i < n; i++)
    if ((int)s[i].size() && s[i][1] == 'h') {
      int l = 0, r = (int)s[i].size();
      while (s[i][l] != '(') l++;
      while (s[i][r] != ')') r--;
      for (int j = l + 1; j <= r - 1; j++) block += s[i][j];
      x = i;
    }
  for (int i = 0; i < n; i++)
    if (s[i][1] == 'r') {
      cnt++;
      a[cnt] = i;
    } else if (s[i][0] == 'c') {
      int l = 0;
      string name = "";
      while (s[i][l] != '(') l++;
      l++;
      while (s[i][l] != ',') {
        name += s[i][l];
        l++;
      }
      if (name == block && a[cnt] < x) {
        name = "";
        l += 2;
        while (s[i][l] != '"') {
          name += s[i][l];
          l++;
        }
        cout << name;
        return 0;
      }
      cnt--;
    }
  cout << "Unhandled Exception";
  return 0;
}
