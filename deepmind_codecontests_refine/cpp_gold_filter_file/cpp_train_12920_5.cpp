#include <bits/stdc++.h>
using namespace std;
const long long int N = 2e5 + 5, MOD = 1000000007, M = 1e4;
string str;
long long int l, a, A, d, t;
int main() {
  cin >> t;
  while (t--) {
    a = A = d = 0;
    cin >> str;
    l = str.length();
    for (int i = 0; i < l; i++) {
      if (str[i] >= '0' && str[i] <= '9')
        d++;
      else if (str[i] >= 'a' && str[i] <= 'z')
        a++;
      else
        A++;
    }
    if (!a) {
      if (A > 1) {
        for (int i = 0; i < l; i++) {
          if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = 'a', A--, a++;
            break;
          }
        }
      } else if (d > 1) {
        for (int i = 0; i < l; i++) {
          if (str[i] >= '0' && str[i] <= '9') {
            str[i] = 'a', d--, a++;
            break;
          }
        }
      }
    }
    if (!A) {
      if (a > 1) {
        for (int i = 0; i < l; i++) {
          if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = 'A', A++, a--;
            break;
          }
        }
      } else if (d > 1) {
        for (int i = 0; i < l; i++) {
          if (str[i] >= '0' && str[i] <= '9') {
            str[i] = 'A', d--, A++;
            break;
          }
        }
      }
    }
    if (!d) {
      if (A > 1) {
        for (int i = 0; i < l; i++) {
          if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = '1', d++, A--;
            break;
          }
        }
      } else if (a > 1) {
        for (int i = 0; i < l; i++) {
          if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = '1', d++, a--;
            break;
          }
        }
      }
    }
    cout << str << endl;
  }
  return 0;
}
