#include <bits/stdc++.h>
using namespace std;
long long n, k, kk = 0;
string s;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  cin >> s;
  for (int i = (0); i < (n); i++) {
    if (s[i] == '4' && s[i + 1] == '7') {
      if (!((i + 1) & 1)) {
        if (i) {
          if (s[i - 1] == '4') {
            if (k & 1) {
              s[i] = '7', s[i + 1] = '7';
              break;
            } else {
              s[i] = '4', s[i + 1] = '7';
              break;
            }
          } else {
            s[i + 1] = '7', s[i] = '7', k--;
          }
        } else {
          s[i + 1] = '7', s[i] = '7', k--;
        }
      } else {
        if ((i + 1) & 1) {
          if (i + 2 < n) {
            if (s[i + 2] == '7') {
              if (k & 1) {
                s[i] = '4', s[i + 1] = '4';
                break;
              } else {
                s[i] = '4', s[i + 1] = '7';
                break;
              }
            } else
              s[i] = '4', s[i + 1] = '4', k--;
          } else
            s[i] = '4', s[i + 1] = '4', k--;
        }
      }
    }
  }
  cout << s << endl;
  return 0;
}
