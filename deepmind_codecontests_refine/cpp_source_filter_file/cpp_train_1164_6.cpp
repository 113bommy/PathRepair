#include <bits/stdc++.h>
using namespace std;
long long n, k, i, j;
char c[101100];
int main() {
  cin >> n >> k >> c;
  for (i = 1; i < n; ++i)
    if (c[i - 1] == '4' && c[i] == '7') {
      if (i % 2)
        if (i + 1 < n && c[i + 1] == '7') {
          if (k % 2) {
            c[i - 1] = c[i] = '4';
            i++;
          } else {
            i++;
          }
          break;
        } else {
          c[i] = c[i - 1] = '4';
          k--;
        }
      else if (i - 2 >= 0 && c[i - 2] == '4') {
        if (k % 2) {
          c[i - 1] = c[i] = '7';
          i++;
        } else {
          i++;
        }
        break;
      } else {
        c[i] = c[i - 1] = '7';
        k--;
      }
    }
  cout << c;
  return 0;
}
