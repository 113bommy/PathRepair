#include <bits/stdc++.h>
using namespace std;
const long long int big = 1000000009;
vector<long long int> v;
vector<long long int> v1;
long long int f1 = 0, f2 = 0, ct = 0, ans = 0;
long double pi = 3.14159265;
int main(int argc, char *argv[]) {
  string str;
  cin >> str;
  string req = "", z = "";
  long long int a = 0, b = 0, c = 0, d = 0;
  for (int i = 0; i < str.size(); i++) {
    char x = str[i];
    if (x == '1' and a == 0)
      a++;
    else if (x == '8' and b == 0)
      b++;
    else if (x == '6' and c == 0)
      c++;
    else if (x == '9' and d == 0)
      d++;
    else if (x != '0')
      req += x;
    else
      z += x;
  }
  long long int prev = 0;
  for (int i = 0; i < req.size(); i++) {
    long long int cur = prev * 10 + int(req[i]) - 47;
    prev = cur % 7;
  }
  string ans = "";
  if (prev == 0) ans += req + "1869" + z;
  if (prev == 6) ans += req + "1698" + z;
  if (prev == 5) ans += req + "1968" + z;
  if (prev == 4) ans += req + "1986" + z;
  if (prev == 3) ans += req + "1689" + z;
  if (prev == 2) ans += req + "1896" + z;
  if (prev == 1) ans += req + "6198" + z;
  cout << ans << " " << endl;
  return 0;
}
