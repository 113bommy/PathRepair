#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int cnt[70];
long long int pow_mod(long long int a, long long int b, long long int m) {
  if (b == 0) return 1;
  long long int temp = pow_mod(a, b / 2, m);
  temp = (temp * temp) % m;
  if (b & 1) temp = (temp * a) % m;
  return temp;
}
int main() {
  cnt[0] = 1;
  for (int i = 1; i <= 64; i++) {
    int num = i, cnts = 0;
    for (int j = 0; j < 6; j++) {
      if (!(num >> j & 1)) cnts++;
    }
    cnt[i] = cnts;
  }
  long long int tc = 0;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    char x = s[i];
    int y;
    if (isdigit(x)) {
      y = x - '0';
      cerr << "y"
           << ": " << y << endl;
      ;
    } else if (isupper(x)) {
      y = x - 'A' + 10;
      cerr << "y"
           << ": " << y << endl;
      ;
    } else if (x == '-') {
      y = 62;
    } else if (x == '_') {
      y = 63;
    } else {
      y = x - 'a' + 36;
    }
    tc += cnt[y];
  }
  tc = pow_mod(3, tc, MOD);
  cout << tc << endl;
}
