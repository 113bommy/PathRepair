#include <bits/stdc++.h>
using namespace std;
long long n, m, a, num;
string s[45];
int main() {
  cin >> n >> m;
  m /= 2;
  for (int i = 1; i <= n; i++) cin >> s[i];
  for (int i = n; i >= 1; i--) {
    a *= 2;
    if (s[i] == "halfplus") a += 1;
    num += a;
  }
  num *= m;
  cout << num;
  return 0;
}
