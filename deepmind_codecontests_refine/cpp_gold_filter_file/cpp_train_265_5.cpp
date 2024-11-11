#include <bits/stdc++.h>
using namespace std;
int n, k, a[1000008], t;
string s;
int main() {
  cin >> n;
  cin >> s;
  for (k = 0; k < n - 1; k++)
    if ((s[k] == 'e' && s[k + 1] == 'e' && s[k - 1] != 'e' &&
         s[k + 2] != 'e') ||
        (s[k] == 'o' && s[k + 1] == 'o' && s[k - 1] != 'o' && s[k + 2] != 'o'))
      t++;
    else if (s[k] == 'a' || s[k] == 'e' || s[k] == 'i' || s[k] == 'o' ||
             s[k] == 'u' || s[k] == 'y') {
      if (s[k + 1] == s[k]) a[k + 1]++;
    }
  for (k = 0; k < n; k++)
    if (a[k] == 0) cout << s[k];
}
