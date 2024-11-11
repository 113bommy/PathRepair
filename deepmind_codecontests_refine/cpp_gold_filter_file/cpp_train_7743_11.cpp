#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, m = 1;
  char s;
  cin >> n >> k >> s;
  while (n--) {
    cin >> s;
    if (s == '#') {
      while (m < k) {
        cin >> s;
        m++;
        n--;
        if (s == '.') break;
      }
      if (m = k && s == '#') {
        cout << "NO";
        return 0;
      }
    }
    m = 1;
  }
  cout << "YES";
  return 0;
}
