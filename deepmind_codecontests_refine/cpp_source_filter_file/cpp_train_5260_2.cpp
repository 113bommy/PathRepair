#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, l;
  cin >> n >> k;
  string s, s1;
  cin >> s;
  if (k == 0)
    cout << s;
  else {
    s1 = s;
    i = 0;
    while (k > 0 && i < n) {
      if (s[i] - 'a' > 'z' - s[i]) {
        if (s[i] - 'a' > k) {
          s1[i] = s1[i] - k;
          k = 0;
        } else {
          k -= s[i] - 'a';
          s1[i] = 'a';
        }
      } else {
        if ('z' - s[i] > k) {
          s1[i] = s1[i] - k;
          k = 0;
        } else {
          k -= 'z' - s[i];
          s1[i] = 'z';
        }
      }
      i++;
    }
    if (k == 0)
      cout << s1;
    else
      cout << -1;
  }
}
