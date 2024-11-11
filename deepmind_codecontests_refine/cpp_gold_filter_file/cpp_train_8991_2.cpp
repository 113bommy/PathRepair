#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if (!i && (s[0] != '"') && (s[0] != ' ')) {
      int j = 1;
      while ((s[j] != '"') && (s[j] != ' ') && (j < n)) j++;
      cout << "<";
      for (int k = 0; k < j; k++) cout << s[k];
      cout << ">" << endl;
    } else if (s[i] == '"') {
      int j = i + 1;
      while (s[j] != '"') j++;
      cout << "<";
      for (int k = i + 1; k < j; k++) cout << s[k];
      cout << ">" << endl;
      i = j;
    } else {
      if (s[i] == ' ') {
        while ((s[i] == ' ') && (i < n)) i++;
        if (i == n) {
          return 0;
        }
        if (s[i] == '"') {
          int j = i + 1;
          while (s[j] != '"') j++;
          cout << "<";
          for (int k = i + 1; k < j; k++) cout << s[k];
          cout << ">" << endl;
          i = j;
        } else {
          int a = i;
          while ((s[i] != ' ') && (i < n)) i++;
          cout << "<";
          for (int k = a; k < i; k++) cout << s[k];
          cout << ">" << endl;
          i--;
        }
      }
    }
  }
  return 0;
}
