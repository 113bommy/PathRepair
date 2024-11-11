#include <bits/stdc++.h>
using namespace std;
char x[256];
int n;
long long hasha[1000001], hashb[1000001], pw[1000001];
string a, b;
long long modulo = 1e9 + 7;
void pre() {
  x['E'] = 'W';
  x['W'] = 'E';
  x['N'] = 'S';
  x['S'] = 'N';
}
void calc() {
  pw[0] = 1;
  for (int i = 1; i < n; i++) {
    pw[i] = 10 * pw[i - 1];
    hasha[i] = 10 * hasha[i - 1] + a[i - 1];
    hashb[i] = 10 * hashb[i - 1] + b[i - 1];
    pw[i] %= modulo;
    hasha[i] %= modulo;
    hashb[i] %= modulo;
  }
}
void orbit(string &s) {
  int i = 0, j = s.length() - 1;
  while (i < j) {
    swap(s[i], s[j]);
    ++i;
    --j;
  }
}
void reverse(string &s) {
  for (int i = 0; i < s.length(); i++) s[i] = x[s[i]];
}
int main() {
  cin >> n;
  pre();
  cin >> a >> b;
  orbit(a);
  reverse(a);
  calc();
  int flag = 1;
  for (int i = 1; i < n; i++) {
    if (hasha[i] ==
        ((hashb[n - 1] - hashb[n - 1 - i] * pw[i]) % modulo + modulo) %
            modulo) {
      flag = 0;
    }
  }
  if (flag)
    cout << "YES";
  else
    cout << "NO";
}
