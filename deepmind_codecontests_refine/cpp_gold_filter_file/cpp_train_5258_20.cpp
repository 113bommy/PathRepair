#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> n >> t;
  t = n - t;
  string s1, s2;
  cin >> s1 >> s2;
  int dif = 0;
  for (int i = 0; i < s1.size(); i++)
    if (s1[i] != s2[i]) dif++;
  if (2 * n - dif < 2 * t) {
    cout << "-1" << endl;
    return 0;
  }
  string s3 = "";
  int t1 = 0, t2 = 0;
  for (int i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      if (t1 != t2) {
        if (t1 < t2) {
          s3 = s3 + s1[i];
          t1++;
        } else {
          s3 = s3 + s2[i];
          t2++;
        }
        dif--;
      } else {
        if (t1 < t && dif > 1) {
          s3 = s3 + s1[i];
          t1++;
          dif--;
        } else {
          if ('a' != s1[i] && 'a' != s2[i])
            s3 = s3 + 'a';
          else {
            if ('b' != s1[i] && 'b' != s2[i])
              s3 = s3 + 'b';
            else
              s3 = s3 + 'c';
          }
        }
      }
    } else {
      if (t1 < t) {
        s3 = s3 + s1[i];
        t1++;
        t2++;
      } else {
        if ('b' != s1[i] && 'b' != s2[i])
          s3 = s3 + 'b';
        else
          s3 = s3 + 'c';
      }
    }
  }
  cout << s3 << endl;
  return 0;
}
