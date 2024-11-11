#include <bits/stdc++.h>
using namespace std;
const int inf = 2009000999;
const double eps = 1e-3;
const int maxn = 1e5 + 55;
const int maxk = 55;
const int base = 1073741789;
const long long basell = 1e18 + 3;
const long double PI = acos(-1.0);
string itosm(long long x) {
  string ans = "";
  while (x > 0) {
    ans += ((x % 10) + '0');
    x /= 10;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
long long stoim(string str) {
  long long ans = 0;
  long long k = 1;
  for (int i = str.length() - 1; i >= 0; i--) {
    ans += (str[i] - '0') * k;
    k *= 10;
  }
  return ans;
}
int a[maxn];
int main() {
  int a, b;
  cin >> a >> b;
  if (a > b) {
    cout << "First";
  } else {
    cout << "Second";
  }
  return 0;
}
