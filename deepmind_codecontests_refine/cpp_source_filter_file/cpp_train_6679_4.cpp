#include <bits/stdc++.h>
using namespace std;
const int N = int(2e5) + 2;
const int LG = 20;
const long long mod = 998244353;
const int INF = 2147483647;
const long long linf = 1e18;
const long double pi = acos(-1);
const long double EPS = 1e-10;
int n;
string s, ans;
int main() {
  cin >> n;
  cin >> s;
  for (int i = 0; i < ((int)(s).size()); ++i) {
    int j = i;
    while (i + 1 < ((int)(s).size()) && s[i] == s[j]) j++;
    if (s[j] != s[i]) {
      ans += s[i];
      ans += s[j];
    }
    i = j;
  }
  cout << n - ((int)(ans).size()) << " " << ans;
  return 0;
}
