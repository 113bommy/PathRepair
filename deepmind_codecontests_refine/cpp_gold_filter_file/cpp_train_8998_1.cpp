#include <bits/stdc++.h>
const long long MOD = 1e9 + 7;
const int EPS = 1e-9;
const long double PI = acos(-1.0);
const int MAXX = 3e5 + 3;
const int LOGMAXN = 30;
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  string s;
  cin >> s;
  long long sum = 0;
  for (int i = 0; i < s.length(); ++i) {
    sum = (sum * 10) + (s[i] - '0');
  }
  if (sum % 4 == 0)
    cout << 4 << endl;
  else
    cout << 0 << endl;
  return 0;
}
