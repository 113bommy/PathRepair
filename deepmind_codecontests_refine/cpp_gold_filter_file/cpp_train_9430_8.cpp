#include <bits/stdc++.h>
using namespace std;
char str1[105], str2[105], str3[105];
int main() {
  int n, m, i, j, k, r, g, b, s = 0, c = 0, d = 0, f = 0;
  gets(str1);
  gets(str2);
  gets(str3);
  i = strlen(str1);
  j = strlen(str2);
  k = strlen(str3);
  for (r = 0; r < i; r++) {
    if (str1[r] == 'a' || str1[r] == 'e' || str1[r] == 'o' || str1[r] == 'i' ||
        str1[r] == 'u') {
      c++;
    }
  }
  if (c != 5) {
    cout << "NO";
    return 0;
  }
  for (r = 0; r < j; r++) {
    if (str2[r] == 'a' || str2[r] == 'e' || str2[r] == 'o' || str2[r] == 'i' ||
        str2[r] == 'u') {
      d++;
    }
  }
  if (d != 7) {
    cout << "NO";
    return 0;
  }
  for (r = 0; r < k; r++) {
    if (str3[r] == 'a' || str3[r] == 'e' || str3[r] == 'o' || str3[r] == 'i' ||
        str3[r] == 'u') {
      f++;
    }
  }
  if (f != 5) {
    cout << "NO";
    return 0;
  }
  cout << "YES";
}
