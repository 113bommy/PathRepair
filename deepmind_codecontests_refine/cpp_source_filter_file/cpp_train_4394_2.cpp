#include <bits/stdc++.h>
using namespace std;
const int N = 22e4;
char s[N * 2];
int l[N * 2], r[N * 2];
int main() {
  ios::sync_with_stdio(0);
  int n, k;
  cin >> n >> k >> s;
  for (int i = 0; i < n; i++) s[i + n] = s[i];
  for (int i = 0, lx = 0; i < n * 2; i++) {
    if (s[i] == s[i + 1]) lx = i + 1;
    l[i + 1] = lx;
  }
  for (int i = n * 2 - 1, rx = n * 2; i > 0; i--) {
    if (s[i] == s[i - 1]) rx = i - 1;
    r[i - 1] = rx;
  }
  for (int i = 0; i < n; i++) {
    if (i + n - l[i + n] < r[i] - i) {
      if (i + n - l[i + n] <= k)
        cout << s[l[i + n]];
      else if (k & 1)
        cout << (s[i] == 'W' ? 'B' : 'W');
      else
        cout << s[i];
    } else {
      if (r[i] - i <= k)
        cout << s[r[i]];
      else if (k & 1)
        cout << (s[i] == 'W' ? 'B' : 'W');
      else
        cout << s[i];
    }
  }
  return 0;
}
