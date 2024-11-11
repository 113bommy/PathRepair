#include <bits/stdc++.h>
using namespace std;
long long int i, x, y, n, j, ar[100000], a[100000], co, r, m, k, ga[32][2];
string s, f;
char t = 'a';
int main(int argc, char** argv) {
  cin >> s >> f;
  x = f.length();
  y = 1;
  while (j <= (x - 1)) {
    if (f[j] == s[i]) {
      if (y <= x) {
        y++;
        i++;
      }
    }
    j++;
  }
  cout << y;
  return 0;
}
