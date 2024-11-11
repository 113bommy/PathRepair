#include <bits/stdc++.h>
using namespace std;
int A[30];
int main() {
  int a = 0, c = 0, g = 0, t = 0, q = 0;
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (s.length() % 4) {
    cout << "====" << endl;
    return 0;
  }
  int temp = n / 4;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A')
      a++;
    else if (s[i] == 'C')
      c++;
    else if (s[i] == 'G')
      g++;
    else if (s[i] == 'T')
      t++;
    else if (s[i] == '?')
      q++;
  }
  if (a > temp || c > temp || g > temp || t > temp) {
    cout << "====" << endl;
    return 0;
  } else {
    for (int i = 0; i < n; i++) {
      if (s[i] == '?') {
        if (a < temp) {
          s[i] = 'A';
          a++;
        } else if (c < temp) {
          s[i] = 'C';
          c++;
        } else if (g < temp) {
          s[i] = 'G';
          g++;
        } else if (t < temp) {
          s[i] = 'T';
          t++;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      cout << s[i];
    }
  }
}
