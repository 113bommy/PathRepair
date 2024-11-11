#include <bits/stdc++.h>
const int maxi = 2000000000;
const int maxq = 1000000000;
const double eps = 1e-10;
const double pi = 3.1415926535897932;
const double inf = 1e+18;
const int mo = 1000000007;
using namespace std;
set<int> k;
set<int>::iterator it;
int n, kk;
char s[1111111];
int main() {
  cin >> n >> kk;
  scanf("\n");
  gets(s);
  for (int i = 0; (i < n - 1) && kk; i++)
    if (s[i] == '4' && s[i + 1] == '7') {
      if (i % 2 == 0) {
        s[i] = '4';
        s[i + 1] = '4';
        kk--;
      }
      if (i % 2 == 1) {
        s[i] = '7';
        s[i + 1] = '7';
        if (i - 1 >= 0) {
          if (s[i - 1] == '4' && i % 2 == 1) {
            if (((kk)&1)) {
              puts(s);
              return 0;
            } else {
              s[i] = '4';
              puts(s);
              return 0;
            }
          }
          if (s[i - 1] == '4') i -= 2;
        }
        kk--;
      }
      if (!kk) break;
    }
  puts(s);
  return 0;
}
