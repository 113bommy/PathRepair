#include <bits/stdc++.h>
using namespace std;
long long n, c[200005], ans, a, b;
int main() {
  string s;
  cin >> n >> s;
  string ans = "";
  int xet = 1;
  for (int i = 0; i <= n - 1; i++) {
    i = i + xet - 1;
    ans = ans + s[i];
    xet++;
  }
  cout << ans;
}
