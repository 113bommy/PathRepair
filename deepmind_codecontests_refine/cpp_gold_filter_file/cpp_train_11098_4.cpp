#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
long long f[555], n;
string g[] = {"<", "^", ">", "v"};
string s, t;
int main() {
  cin >> s >> t;
  cin >> n;
  if (n % 2 == 0) {
    cout << "undefined";
    return 0;
  }
  for (int i = 0; i < 4; i++)
    if (s == g[i]) {
      if (g[(i + (n % 4)) % 4] == t)
        cout << "cw";
      else
        cout << "ccw";
    }
}
