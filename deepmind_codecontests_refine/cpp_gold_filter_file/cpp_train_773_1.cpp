#include <bits/stdc++.h>
using namespace std;
bool a[27];
int main() {
  int n, p;
  cin >> n >> p;
  string s, r = "";
  cin >> s;
  for (int i = n - 1; i >= 0; i--) {
    int d = (int)s[i] - 96;
    for (int j = d + 1; j <= p; j++) {
      char g = (char)(j + 96);
      if (g != s[i - 2] && g != s[i - 1]) {
        for (int k = 0; k < i; k++) r += s[k];
        r += g;
        for (int k = i + 1; k < s.length(); k++) {
          for (int j = 1; j <= p; j++) {
            char g = (char)(j + 96);
            if (g != r[k - 2] && g != r[k - 1]) {
              r += g;
              break;
            }
          }
        }
        cout << r;
        return 0;
      }
    }
  }
  cout << "NO";
  return 0;
}
