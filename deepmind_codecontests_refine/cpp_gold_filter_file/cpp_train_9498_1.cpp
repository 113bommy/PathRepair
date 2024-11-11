#include <bits/stdc++.h>
using namespace std;
int n;
int a[111111];
int reverse(int a) {
  int res = 0;
  for (int i = 0; i < 8; i++) {
    if (a & 1) {
      res = res * 2 + 1;
    } else {
      res = res * 2;
    }
    a >>= 1;
  }
  return res;
}
string s;
char s2[111111];
int main() {
  gets(s2);
  s = s2;
  for (int i = 0; i < s.size(); i++) {
    int t = 0;
    if (i) t = s[i - 1];
    int k = s[i];
    a[i] = (reverse(t) - reverse(k) + 256) % 256;
  }
  for (int i = 0; i < s.size(); i++) printf("%d\n", a[i]);
  return 0;
}
