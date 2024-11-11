#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, p;
  cin >> n >> p;
  string s;
  cin >> s;
  string temp = s;
  long long int cur = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] - 'a' + 1 <= p) {
      char c = s[i];
      while (1) {
        c++;
        if (c - 'a' + 1 > p) break;
        cur = 0;
        if ((i - 1 >= 0) && (s[i - 1] == c)) cur++;
        if ((i - 2 >= 0) && (s[i - 2] == c)) cur++;
        if (cur == 0) {
          s[i] = c;
          bool b = 0;
          for (int j = i + 1; j < n; j++) {
            b = 0;
            for (char ch = 'a'; ch <= p + 'a' - 1; ch++) {
              long long int t = 0;
              if ((j - 1 >= 0) && (s[j - 1] == ch)) t++;
              if ((j - 2 >= 0) && (s[j - 2] == ch)) t++;
              if (t == 0) {
                s[j] = ch;
                b = 1;
                break;
              }
            }
            if (b == 0) {
              s = temp;
              break;
            }
          }
          if ((b == 1) || (i == n - 1)) {
            cout << s;
            return 0;
          } else
            s = temp;
        }
      }
    }
  }
  cout << "NO";
}
