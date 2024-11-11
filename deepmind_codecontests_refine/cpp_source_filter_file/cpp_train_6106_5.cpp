#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main() {
  int n;
  cin >> n;
  int l = -1e9 - 1;
  int r = 1e9 + 1;
  for (int i = 0; i < n; i++) cin >> a[i];
  string s;
  cin >> s;
  for (int i = 4; i < n; i++) {
    if (s[i - 1] == s[i - 2] && s[i - 2] == s[i - 3] && s[i - 4] == s[i - 3] &&
        s[i - 1] == '0') {
      if (s[i] == '1') {
        int maxim = max(a[i], a[i - 1]);
        maxim = max(maxim, max(a[i - 2], a[i - 3]));
        maxim = max(maxim, a[i - 4]);
        l = max(l, maxim + 1);
      }
    } else if (s[i - 1] == s[i - 2] && s[i - 2] == s[i - 3] &&
               s[i - 4] == s[i - 3] && s[i - 1] == '0') {
      if (s[i] == '0') {
        int minim = min(a[i], a[i - 1]);
        minim = min(minim, min(a[i - 2], a[i - 3]));
        minim = min(minim, a[i - 4]);
        r = min(r, minim - 1);
      }
    } else {
      continue;
    }
  }
  cout << l << ' ' << r;
  return 0;
}
