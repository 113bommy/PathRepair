#include <bits/stdc++.h>
using namespace std;
ifstream in("nrnot.in");
ofstream out("nrnot.out");
int main() {
  char s[1000001];
  cin >> s;
  int l, r, sizes;
  l = 0;
  r = strlen(s) - 1;
  sizes = 3;
  while (l < r && s[l] == s[r] && sizes >= 3) {
    char c = s[l];
    sizes = 0;
    while (s[l] == c) {
      l++;
      sizes++;
    }
    while (s[r] == c && r >= 1) {
      r--;
      sizes++;
    }
  }
  if (l > r && sizes >= 2)
    cout << sizes;
  else
    cout << 0;
  return 0;
}
