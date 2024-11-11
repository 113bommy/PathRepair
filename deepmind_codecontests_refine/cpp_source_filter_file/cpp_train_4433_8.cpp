#include <bits/stdc++.h>
using namespace std;
int a[255];
int main() {
  int i, x, j = 0, n;
  scanf("%d", &n);
  char s[n];
  scanf("%s", s);
  if (n % 4 != 0) {
    cout << "===" << endl;
    return 0;
  } else {
    for (i = 0; i < n; i++) {
      x = s[i];
      a[x]++;
    }
  }
  if (a[65] > n / 4 || a[67] > n / 4 || a[71] > n / 4 || a[84] > n / 4) {
    cout << "===" << endl;
    return 0;
  }
  for (i = 0; i < n; i++) {
    if (s[i] == '?' && a[65] < n / 4) {
      s[i] = 'A';
      a[65]++;
      if (a[65] == n / 4) {
        break;
      }
    }
  }
  for (i = 0; i < n; i++) {
    if (s[i] == '?' && a[66] < n / 4) {
      s[i] = 'C';
      a[67]++;
      if (a[67] == n / 4) {
        break;
      }
    }
  }
  for (i = 0; i < n; i++) {
    if (s[i] == '?' && a[71] < n / 4) {
      s[i] = 'G';
      a[71]++;
      if (a[71] == n / 4) {
        break;
      }
    }
  }
  for (i = 0; i < n; i++) {
    if (s[i] == '?' && a[84] < n / 4) {
      s[i] = 'T';
      a[84]++;
      if (a[84] == n / 4) {
        break;
      }
    }
  }
  cout << s << endl;
  return 0;
}
