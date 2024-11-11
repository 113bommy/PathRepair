#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int k, l, i, j, n, co = 0, f = 0, c = 0;
  cin >> s >> k;
  char a[k];
  l = s.length();
  for (i = 0; i < l; i++) {
    if (s[i] == '*') f++;
    if (s[i] == '?') c++;
  }
  if (k < l - 2 * (f + c)) {
    cout << "Impossible";
    return 0;
  } else if (k > l - (f + c) && f == 0) {
    cout << "Impossible";
    return 0;
  } else {
    j = 0;
    if (k <= l - (f + c)) {
      for (i = 0; i < l; i++) {
        if (s[i] == '*' || s[i] == '?')
          continue;
        else if (i != l - 1 && (s[i + 1] == '*' || s[i + 1] == '?') &&
                 co != l - (f + c + k)) {
          co++;
          continue;
        } else {
          a[j] = s[i];
          j++;
        }
      }
    } else {
      for (i = 0; i < l; i++) {
        if (s[i] == '*' || s[i] == '?')
          continue;
        else if (i != l - 1 && s[i + 1] == '*' && co == 0) {
          for (n = 1; n <= k + f + c - l; n++) {
            a[j] = s[i];
            j++;
          }
          co++;
        } else {
          a[j] = s[i];
          j++;
        }
      }
    }
  }
  for (i = 0; i < k; i++) cout << a[i];
  return 0;
}
