#include <bits/stdc++.h>
using namespace std;
long long n, ans = 1, tmp = 1, curans = 1;
long long value(string str) {
  long long ret = 1;
  for (int i = 0; i < str.size(); i++) ret *= (str[i] - '0');
  return ret;
}
int main() {
  cin >> n;
  string str = to_string(n);
  for (int i = 0; i < str.size(); i++) {
    tmp = curans;
    for (int j = i + 1; j < str.size(); j++) tmp *= 9;
    if (str[i] != '1') tmp *= (str[i] - '0') - 1;
    ans = max(ans, tmp);
    curans *= str[i] - '0';
  }
  ans = max(ans, value(str));
  for (int i = 0; i < 5e6; i++) {
    ans = max(ans, value(to_string((rand() % n) + 1)));
  }
  cout << ans << endl;
  return 0;
}
