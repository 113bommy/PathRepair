#include <bits/stdc++.h>
using namespace std;
int n, i, j;
unsigned long long h1[2], h2[2], e[2] = {1000000007, 1000000009}, p[2];
string s, t;
int main() {
  ios::sync_with_stdio(false);
  ;
  cin >> n >> s >> t;
  n--;
  for (i = 0; i < n; i++) {
    if (s[i] == 'W')
      s[i] = 'E';
    else if (s[i] == 'S')
      s[i] = 'N';
    else if (s[i] == 'E')
      s[i] = 'E';
    else if (s[i] == 'N')
      s[i] = 'S';
  }
  p[0] = p[1] = 1;
  for (i = n - 1; ~i; i--) {
    for (j = 0; j <= 1; j++) {
      h1[j] = h1[j] * e[j] + t[i];
      h2[j] = h2[j] + p[j] * s[i];
      p[j] *= e[j];
    }
    if (h1[1] == h2[1] && h1[0] == h2[0]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
