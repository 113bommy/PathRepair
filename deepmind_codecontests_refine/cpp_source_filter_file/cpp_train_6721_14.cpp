#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  int mx = 0, i = 0;
  while (i < s.length() && s[i] == '<') {
    mx++;
    i++;
  }
  int mx2 = 0;
  i = s.length() - 1;
  while (i >= 0 && s[i] == '>') {
    i--;
    mx2++;
  }
  cout << max(mx, mx2);
}
