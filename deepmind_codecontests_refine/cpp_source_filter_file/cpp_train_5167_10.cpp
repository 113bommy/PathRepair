#include <bits/stdc++.h>
using namespace std;
string s;
int poz, sol;
int main() {
  sol = INT_MAX;
  cin >> s;
  int n = s.size();
  for (int c = 1; c <= 26; c++) {
    char ch = c + 'a' - 1;
    poz = 0;
    int maxx = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == ch) {
        if (i - poz > maxx) maxx = i - poz;
        poz = i;
      }
    }
    if (n - poz > maxx) maxx = n - poz;
    if (sol > maxx) sol = maxx;
  }
  cout << sol;
  return 0;
}
