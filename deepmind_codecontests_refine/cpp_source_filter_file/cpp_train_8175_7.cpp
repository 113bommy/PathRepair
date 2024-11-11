#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  long long n = s.size();
  long long m;
  if (n % 2 == 0)
    m = n / 2;
  else
    m = (n + 1) / 2;
  char v[] = {'A', 'H', 'I', 'M', 'm', 'O', 'o', 'T',
              'U', 'X', 'V', 'v', 'x', 'Y', 'W', 'w'};
  long long o = sizeof(v) / sizeof(v[0]);
  long long c = 0;
  if (n == 1) {
    for (long long j = 0; j < o; j++) {
      if (v[j] == s[0]) {
        cout << "TAK";
        return 0;
      }
    }
    cout << "NIE";
    return 0;
  }
  for (long long i = 0; i < m; i++) {
    if (s[i] == 'b' && s[n - 1 - i] == 'd' ||
        s[i] == 'p' && s[n - 1 - i] == 'q' ||
        s[i] == 'd' && s[n - 1 - i] == 'b' ||
        s[i] == 'q' && s[n - 1 - i] == 'p') {
      c++;
      continue;
    } else if (s[n - i - 1] == s[i]) {
      for (long long j = 0; j < o; j++) {
        if (v[j] == s[i]) {
          c++;
          break;
        }
      }
    }
  }
  if (c == m)
    cout << "TAK";
  else
    cout << "NIE";
  return 0;
}
