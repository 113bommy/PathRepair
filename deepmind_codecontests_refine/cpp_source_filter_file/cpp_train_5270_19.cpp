#include <bits/stdc++.h>
using namespace std;
string s;
char c[] = {'a', 'o', 'u', 'i', 'e'};
int a[3007], i, j, k;
bool bar, br;
int main() {
  cin >> s;
  for (j = 0; j < 6; j++)
    if (s[0] == c[j]) {
      bar = 1;
      break;
    }
  if (!bar) a[0] = 1;
  cout << s[0];
  for (i = 1; i < s.size(); i++) {
    bar = 0;
    for (j = 0; j < 6; j++)
      if (s[i] == c[j]) {
        bar = 1;
        break;
      }
    if (bar)
      cout << s[i], br = 0;
    else {
      if (s[i] != s[i - 1] && a[i - 1] > 0) br = 1;
      a[i] = a[i - 1] + 1;
      if (a[i] >= 3 && br == 1) {
        cout << " " << s[i];
        br = 0;
        a[i] = 1;
      } else
        cout << s[i];
    }
  }
}
