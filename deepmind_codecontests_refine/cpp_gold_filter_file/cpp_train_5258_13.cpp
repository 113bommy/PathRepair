#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 4;
string a, b;
char s[N];
int n, t;
int main() {
  cin >> n >> t;
  cin >> a >> b;
  int x = n - t, c = 0;
  for (int i = 0; i < n; i++)
    if (a[i] == b[i]) c++;
  if (x <= c) {
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i] && x) {
        cout << a[i];
        x--;
        continue;
      } else
        for (int j = 0; j < 26; j++)
          if (char(j + 'a') != a[i] && char(j + 'a') != b[i]) {
            cout << char(j + 'a');
            break;
          }
    }
    return 0;
  }
  if (x > c) {
    x -= c;
    if (x * 2 > (n - c)) return puts("-1"), 0;
    int c1 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        s[i] = a[i];
        a[i] = '!';
        c1++;
      }
      if (c1 == x) break;
    }
    c1 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i] && a[i] != '!') {
        s[i] = b[i];
        b[i] = '!';
        c1++;
      }
      if (c1 == x) break;
    }
    for (int i = 0; i < n; i++) {
      if (a[i] != '!' && b[i] != '!') {
        if (a[i] == b[i]) {
          s[i] = a[i];
          x--;
        } else {
          for (int j = 0; j < 26; j++)
            if (char(j + 'a') != a[i] && char(j + 'a') != b[i]) {
              s[i] = char(j + 'a');
              break;
            }
        }
      }
    }
    for (int i = 0; i < n; i++) cout << s[i];
  }
  return 0;
}
