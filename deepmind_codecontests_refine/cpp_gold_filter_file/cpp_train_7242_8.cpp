#include <bits/stdc++.h>
using namespace std;
template <class arm>
inline void fastio(arm &x) {
  bool n = false;
  register int c;
  do c = getchar();
  while ((c < 48 || c > 57) && c != '-');
  if (c == '-') {
    n = true;
    c = getchar();
  }
  for (x = 0; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + c - 48;
  if (n) x = -x;
}
const long long int MAX = 1000000007LL;
const long long int MOD = 1000000007LL;
int main() {
  string s;
  int a[7] = {0};
  cin >> s;
  int i, n = s.size();
  for (i = 0; i < n; ++i) {
    if (s[i] == 'B') a[0] += 1;
    if (s[i] == 'u') a[1] += 1;
    if (s[i] == 'l') a[2] += 1;
    if (s[i] == 'b') a[3] += 1;
    if (s[i] == 'a') a[4] += 1;
    if (s[i] == 'r') a[5] += 1;
    if (s[i] == 's') a[6] += 1;
  }
  n = 0;
  bool b = a[0] >= 1 && a[1] >= 2 && a[2] >= 1 && a[3] >= 1 && a[4] >= 2 &&
           a[5] >= 1 && a[6] >= 1;
  while (b) {
    n++;
    a[0] -= 1, a[1] -= 2, a[2] -= 1, a[3] -= 1, a[4] -= 2, a[5] -= 1, a[6] -= 1;
    b = a[0] >= 1 && a[1] >= 2 && a[2] >= 1 && a[3] >= 1 && a[4] >= 2 &&
        a[5] >= 1 && a[6] >= 1;
  }
  cout << n << endl;
}
