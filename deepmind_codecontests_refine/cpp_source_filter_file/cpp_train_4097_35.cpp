#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.0000001;
const int INF = 1E9;
const int MAXN = 101000;
string s;
int i, j, n;
int a[30];
int main() {
  cin >> s;
  n = s.size();
  for (int ii = 0; ii < (int)(n); ii++) a[int(s[ii] - 'a')]++;
  i = 0;
  while (i < n) {
    j = 30;
    while (j > 0 && a[j] == 0) j--;
    while (i < n && int(s[i] - 'a') != j) {
      a[int(s[i] - 'a')]--;
      i++;
    }
    if (i < n) {
      a[j]--;
      i++;
      cout << char('a' + j);
    }
  }
  return 0;
}
