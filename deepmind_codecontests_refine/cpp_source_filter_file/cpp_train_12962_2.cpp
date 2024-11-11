#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  N--;
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < N; i++) {
    if (s[i] == 'N')
      s[i] = 'S';
    else if (s[i] == 'N')
      s[i] = 'N';
    else if (s[i] == 'E')
      s[i] = 'W';
    else
      s[i] = 'E';
  }
  long long MOD = 1E9 + 7;
  long long P = 1E7 + 7;
  long long a = 0, b = 0, c, crt = 1;
  for (int i = N - 1; i >= 0; i--) {
    if (s[i] == 'N')
      c = 1;
    else if (s[i] == 'S')
      c = 2;
    else if (s[i] == 'E')
      c = 3;
    else if (s[i] == 'W')
      c = 4;
    a += c * crt;
    a = a % MOD;
    crt *= P;
    crt = crt % MOD;
    if (t[i] == 'N')
      c = 1;
    else if (t[i] == 'S')
      c = 2;
    else if (t[i] == 'E')
      c = 3;
    else if (t[i] == 'W')
      c = 4;
    b *= P;
    b = b % MOD;
    b += c;
    b = b % MOD;
    if (a == b) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
