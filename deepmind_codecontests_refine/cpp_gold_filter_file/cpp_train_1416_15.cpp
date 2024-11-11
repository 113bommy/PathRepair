#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long double EPS = 1e-8;
int main(int argc, char* argv[]) {
  string s;
  cin >> s;
  int h, m;
  h = (s[0] - '0') * 10 + s[1] - '0';
  m = (s[3] - '0') * 10 + s[4] - '0';
  while (h > 11) h -= 12;
  printf("%.9f %.9f\n", (h + m / 60.0) * 360 / 12.0, m * 360 / 60.0);
  return 0;
}
