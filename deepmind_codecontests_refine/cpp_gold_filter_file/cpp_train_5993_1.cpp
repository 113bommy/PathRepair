#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i = 0, n, f = 0, c = 0, a = 0, m = 0, k = 0;
  string s;
  cin >> n >> s;
  while (i < n) {
    if (f) {
      if ((s[i] > 64 && s[i] < 92) || (s[i] < 124 && s[i] > 96))
        a++;
      else if (a)
        k++, a = 0;
    } else {
      if ((s[i] > 64 && s[i] < 92) || (s[i] < 124 && s[i] > 96))
        c++;
      else
        m = max(m, c), c = 0;
    }
    if (s[i] == '(') f = 1, a = 0;
    if (s[i] == ')') f = 0;
    i++;
  }
  cout << max(m, c) << " " << k << endl;
}
