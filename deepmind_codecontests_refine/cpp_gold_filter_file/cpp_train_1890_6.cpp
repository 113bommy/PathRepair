#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int i, len = s.size(), cnt = 0;
  string a = "";
  for (i = 0; i < len; i++) {
    if (s[i] != 'a')
      a += s[i];
    else
      cnt++;
  }
  if (a.size() == 0)
    cout << s;
  else if (!cnt) {
    if (s.size() & 1)
      puts(":(");
    else {
      string x = "", y = "";
      for (i = 0; i < s.size(); i++) {
        if (i < s.size() / 2)
          x += s[i];
        else
          y += s[i];
      }
      if (x == y)
        cout << x;
      else
        puts(":(");
    }
  } else {
    if (a.size() & 1) {
      puts(":(");
      return 0;
    }
    string b = "";
    len = a.size() / 2;
    for (i = 0; i < len; i++) b += a[i];
    int j = 0;
    for (i = s.size() - b.size(); i < s.size(); i++) {
      if (s[i] != b[j++]) {
        puts(":(");
        return 0;
      }
    }
    for (i = 0; i < s.size() - b.size(); i++) cout << s[i];
  }
}
