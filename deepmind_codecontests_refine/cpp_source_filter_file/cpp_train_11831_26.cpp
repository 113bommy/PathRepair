#include <bits/stdc++.h>
using namespace std;
const int INF = (int)2e9;
const double EPS = (double)1e-9;
const double PI = (double)acos(-1);
const long long MOD = (long long)1e9 + 7;
void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  string s;
  int len, cnt = 0;
  cin >> s;
  len = s.length();
  for (int i = 0; i < len; i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
        s[i] == 'u') {
      cnt++;
    } else if (s[i] == '0' || s[i] == '2' || s[i] == '4' || s[i] == '6' ||
               s[i] == '8') {
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}
