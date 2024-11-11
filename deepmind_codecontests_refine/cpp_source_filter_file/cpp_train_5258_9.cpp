#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, t, i;
  string s1, s2, s3;
  cin >> n >> t >> s1 >> s2;
  s3 = s1;
  d = 0;
  for (i = 0; i < n; i++)
    if (s1[i] != s2[i]) d++;
  int r = t - d;
  if (d <= t) {
    for (i = 0; i < n; i++) {
      if (s1[i] != s2[i]) {
        if (s1[i] != 'a' && s2[i] != 'a')
          s3[i] = 'a';
        else if (s1[i] != 'b' && s2[i] != 'b')
          s3[i] = 'b';
        else if (s1[i] != 'c' && s2[i] != 'c')
          s3[i] = 'c';
      } else if (s1[i] == s2[i] && r > 0) {
        if (s1[i] != 'a')
          s3[i] = 'a';
        else if (s1[i] != 'b')
          s3[i] = 'b';
        else if (s1[i] != 'c')
          s3[i] = 'c';
        r--;
      }
    }
    cout << s3;
  } else if (d % 2 == 0 && d / 2 <= t) {
    r = -r;
    for (i = 0; i < n && t > 0 && r > 0; i++) {
      if (s1[i] != s2[i]) {
        s3[i] = s2[i];
        t--, r--;
      }
    }
    for (; i < n && t > 0 && r == 0; i++) {
      if (s1[i] != s2[i]) {
        if (s1[i] != 'a' && s2[i] != 'a')
          s3[i] = 'a';
        else if (s1[i] != 'b' && s2[i] != 'b')
          s3[i] = 'b';
        else if (s1[i] != 'c' && s2[i] != 'c')
          s3[i] = 'c';
        t--;
      }
    }
    cout << s3;
  } else
    cout << -1;
  return 0;
}
