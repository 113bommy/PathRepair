#include <bits/stdc++.h>
using namespace std;
char s[1000010];
int main() {
  long long center, i, n, num, l, r;
  cin >> s;
  n = strlen(s);
  for (i = 0; i < n; i++)
    if (s[i] == '=') s[i] = '0';
  for (i = 0; i < n; i++)
    if (s[i] == '^') {
      center = i;
      break;
    }
  for (num = 0, i = 1; (center - i) >= 0 && (center + i) < n; i++) {
    l = s[center - i];
    r = s[center + i];
    if (l == '=')
      l = 0;
    else
      l -= '0';
    if (r == '=')
      r = 0;
    else
      r -= '0';
    num += i * (l - r);
  }
  for (l = i; (center - l) >= 0; l++) num += i * (s[center - l] - '0');
  for (r = i; (center + r) < n; r++) num -= i * (s[center + r] - '0');
  if (num == 0) {
    cout << "balance";
  } else if (num > 0) {
    cout << "left";
  } else {
    cout << "right";
  }
  cout << endl;
  return 0;
}
