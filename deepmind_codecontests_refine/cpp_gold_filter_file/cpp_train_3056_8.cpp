#include <bits/stdc++.h>
using namespace std;
bool ot[200];
int main() {
  string s;
  cin >> s;
  int n = s.length();
  int i = n - 1;
  while (s[n - 1] == '/' && n > 1) n--;
  for (int i = 0; i < n; i++)
    if (s[i] == '/') {
      i++;
      while (s[i] == '/') {
        ot[i] = 1;
        i++;
      }
    }
  for (int i = 0; i < n; i++)
    if (ot[i] == 0) cout << s[i];
}
