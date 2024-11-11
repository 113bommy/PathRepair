#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  while (a != 0 && b != 0) {
    if (a > b) {
      a %= b;
    } else if (a < b) {
      b %= a;
    } else {
      return a;
    }
  }
  return a + b;
}
long long divS(long long a) {
  long long res = 0;
  while (a > 0) {
    res += a % 10;
    a /= 10;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  bool res = false;
  cin >> n;
  vector<string> s(n);
  for (int(i) = 0; (i) < (int)(n); (i)++) {
    cin >> s[i];
    if (s[i][0] == 'O' && s[i][1] == 'O' && !res) {
      s[i][0] = '+';
      s[i][1] = '+';
      res = !res;
    } else if (s[i][3] == 'O' && s[i][4] == 'O' && !res) {
      s[i][3] = '+';
      s[i][5] = '+';
      res = !res;
    }
  }
  if (res) {
    cout << "YES\n";
    for (int(i) = 0; (i) < (int)(n); (i)++) {
      cout << s[i] << endl;
    }
  } else {
    cout << "NO";
  }
  return 0;
}
