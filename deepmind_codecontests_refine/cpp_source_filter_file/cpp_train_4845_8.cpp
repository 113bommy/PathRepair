#include <bits/stdc++.h>
using namespace std;
const long long int maxN = 1e5 + 100;
const long long int maxM = 1e3 + 100;
const long long int mod = 1e9 + 7;
const long long int hmod = 1e16 + 7;
const long double PI = 3.141592653;
const long long int R = 1379;
const long long int INF = 1e18 + 20;
const long long int Inf = 1e9 + 140;
long long int n;
void do_it() {
  string s;
  cin >> s;
  long long int ans = 1989;
  s = s.substr(4);
  reverse(s.begin(), s.end());
  long long int cur = 1;
  for (long long int i = 1; i <= ((int)(s).size()); i++) {
    ans += cur;
    while ((ans / cur) % 10 != s[i - 1] - '0') ans += cur;
    cur *= 10;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  while (n--) do_it();
}
