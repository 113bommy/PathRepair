#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 1, inf = 0, sup = 0, taille = 1, n2 = 0;
  cin >> n;
  string s;
  cin >> s;
  char beg = s[0];
  inf = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] != beg) {
      ans++;
      beg = s[i];
    }
    if (s[i] == s[inf]) {
      if (i == n - 1) {
        if (i - inf + 1 > taille) {
          taille = i - inf + 1;
        }
        if (i - inf + 1 == 2) {
          n2++;
        }
      }
    } else {
      if (i - inf > taille) {
        taille = i - inf;
      }
      if (i - inf == 2) {
        n2++;
      }
      inf = i;
    }
  }
  if (taille > 2 || n2 == 2) {
    ans = ans + 2;
  } else if (n2 == 1) {
    ans++;
  } else {
  }
  cout << ans << endl;
  return 0;
}
